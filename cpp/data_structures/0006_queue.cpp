// Lesson: Queue - FIFO (First-In, First-Out) data structure
// Compile: g++ -o 0006_queue 0006_queue.cpp

#include <iostream>
#include <queue>

int main() {
  // std::queue is a container adapter (usually wraps std::deque)
  std::queue<std::string> q;

  std::cout << "Enqueuing Alice, Bob, Charlie...\n";
  q.push("Alice");
  q.push("Bob");
  q.push("Charlie");

  std::cout << "Front element: " << q.front() << "\n";
  std::cout << "Back element: " << q.back() << "\n";

  std::cout << "Dequeuing elements: ";
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << "\n";

  return 0;
}
