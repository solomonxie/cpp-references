// Lesson: Deque - Double-ended queue (insert/erase at both ends)
// Compile: g++ -o 0007_deque 0007_deque.cpp

#include <deque>
#include <iostream>

int main() {
  // std::deque (pronounced "deck")
  std::deque<int> dq;

  // Both ends operations
  dq.push_back(10);
  dq.push_front(20);
  dq.push_back(30);
  dq.push_front(40);

  // [40, 20, 10, 30]
  std::cout << "Deque contents: ";
  for (int x : dq)
    std::cout << x << " ";
  std::cout << "\n";

  std::cout << "Front: " << dq.front() << ", Back: " << dq.back() << "\n";

  dq.pop_front();
  dq.pop_back();

  std::cout << "After popping ends: ";
  for (int x : dq)
    std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
