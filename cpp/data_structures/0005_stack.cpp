// Lesson: Stack - LIFO (Last-In, First-Out) data structure
// Compile: g++ -o 0005_stack 0005_stack.cpp

#include <iostream>
#include <stack>
#include <vector>

int main() {
  // std::stack is a container adapter (usually wraps std::deque or std::vector)
  std::stack<int> s;

  std::cout << "Pushing 10, 20, 30 onto stack...\n";
  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << "Stack size: " << s.size() << "\n";
  std::cout << "Top element: " << s.top() << "\n"; // Peek

  std::cout << "Popping elements: ";
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop(); // Remove top
  }
  std::cout << "\n";

  return 0;
}
