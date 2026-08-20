# C10K Challenge (C++)

## Scenario

A backend team is replacing a thread-per-connection prototype with a
production-grade edge server capable of holding **10,000+ concurrent
persistent TCP connections** (long-lived, low-traffic — think chat
presence, notification fan-out, or IoT telemetry ingestion) on a single
commodity host, without the process falling over on thread/context-switch
overhead or running out of file descriptors.

The server must accept connections, read framed messages, echo/broadcast
them to relevant peers, and stay responsive under connection churn
(clients connecting/disconnecting continuously) as well as under sustained
idle-hold load.

## Hardware / Machine Constraint

Single-node EC2 instance: **t3.medium (4 GB RAM, 2 vCPUs)**.

- No horizontal scaling, no load balancer — one process, one box.
- `ulimit -n` and kernel network params (`somaxconn`,
  `net.core.rmem_max`/`wmem_max`, ephemeral port range) may be tuned, but
  must be tuned explicitly and documented — not silently raised by the
  test harness.
- Client load generator runs on a **separate** EC2 instance (or several)
  so the server's own CPU/memory isn't shared with the load generator.

## Mission Task List & Expected Outcomes

### Task 1: Non-blocking I/O Event Loop
- Task: Build the server around `epoll` (level- or edge-triggered) rather
  than a thread- or process-per-connection model.
- Expected Outcome: A single (or small fixed pool of) event-loop
  thread(s) handle all socket readiness events; no thread is spawned per
  connection.

### Task 2: Accept & Hold 10,000 Concurrent Connections
- Task: Accept and keep alive 10,000 simultaneous idle-ish TCP
  connections from the load generator.
- Expected Outcome: All 10,000 connections established and held open
  with periodic keepalive traffic, without file-descriptor exhaustion or
  accept-queue drops (`somaxconn` backlog respected, `SO_REUSEADDR`/
  `SO_REUSEPORT` used correctly).

### Task 3: Framed Message Echo/Broadcast
- Task: Implement a simple length-prefixed (or delimiter-based) message
  framing protocol; echo each message back to sender and/or broadcast to
  a subscriber set.
- Expected Outcome: Correct reassembly of partial reads/writes (short
  reads, partial writes, TCP segment coalescing all handled); no message
  corruption or cross-talk between connections under load.

### Task 4: Non-blocking Writes & Backpressure
- Task: Handle slow/stalled readers without blocking the event loop or
  unbounded memory growth.
- Expected Outcome: Per-connection outbound buffer with a bounded size;
  `EAGAIN`/`EWOULDBLOCK` on writes handled via `EPOLLOUT` re-arm; a
  connection that stays backed up past a configured threshold is
  disconnected (documented policy), not left to grow memory unbounded.

### Task 5: Graceful Connection Churn
- Task: Handle clients connecting and disconnecting continuously (e.g.
  10% of connections cycling every second) alongside the steady-state
  10K hold.
- Expected Outcome: No FD leaks, no zombie epoll registrations, clean
  teardown on `EPOLLHUP`/`EPOLLERR`/`recv() == 0`; FD count returns to
  baseline after churn stops.

### Task 6: Resource Accounting & Limits
- Task: Make resource usage observable and bounded.
- Expected Outcome: Per-connection memory overhead documented (target:
  under a few KB/connection); process RSS and open-FD count exposed via
  a metrics endpoint or periodic log line; server enforces a max-
  connection cap and rejects/queues cleanly beyond it rather than
  crashing.

### Task 7: Signal Handling & Clean Shutdown
- Task: Handle `SIGTERM`/`SIGINT` for graceful shutdown.
- Expected Outcome: In-flight messages flushed or explicitly dropped per
  documented policy, listening socket closed first (stop accepting new
  connections), all client sockets closed cleanly, process exits with
  status 0.

## System Validation & Acceptance Criteria

| Area | Target Benchmark | Failure Condition |
|---|---|---|
| Concurrency ceiling | 10,000 concurrent connections held stable for 5+ min | Connection count plateaus below 10K, or connections silently drop |
| CPU efficiency | Idle-load CPU usage stays near 0% across both vCPUs when connections are idle | Busy-polling / high idle CPU (indicates blocking or spin-wait bugs) |
| Memory footprint | RSS stays within a documented linear bound (e.g. < 20 MB baseline + a few KB × connections) | Unbounded growth or OOM-kill under sustained load |
| Latency under load | p99 echo round-trip < 50 ms at 10K connections, moderate message rate | p99 latency degrades unboundedly or times out |
| FD hygiene | Open FD count returns to baseline after churn/disconnect | FD leak (count monotonically increases) |
| Correctness | Zero message loss/corruption across a full load run | Any dropped, duplicated, or corrupted message |
| Stability | No crash, no `epoll_wait` errors, no core dump over test duration | Segfault, deadlock, or unhandled exception under load |

## Time Constraints

- Total test run (ramp-up + steady-state + churn + ramp-down): **< 30
  minutes**
- Stage breakdown targets:
  - Connection ramp-up to 10,000: **< 2 minutes**
  - Steady-state idle hold: **10 minutes**
  - Churn phase (connect/disconnect cycling): **10 minutes**
  - Graceful shutdown (drain + exit): **< 10 seconds**
