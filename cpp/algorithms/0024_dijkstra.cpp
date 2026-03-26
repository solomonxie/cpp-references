/**
 * Dijkstra's Algorithm
 * 
 * Finds the shortest path from a source to all other vertices in a 
 * weighted graph with non-negative edge weights.
 */
#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;

void dijkstra(int s, int V, std::vector<std::vector<pii>>& adj) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    std::vector<int> dist(V, 1e9);
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; ++i) std::cout << "Node " << i << ": " << dist[i] << std::endl;
}

int main() {
    int V = 5;
    std::vector<std::vector<pii>> adj(V);
    adj[0].push_back({1, 9}); adj[0].push_back({2, 6}); adj[0].push_back({3, 5}); adj[0].push_back({4, 3});
    adj[2].push_back({1, 2}); adj[2].push_back({3, 4});
    dijkstra(0, V, adj);
    return 0;
}
