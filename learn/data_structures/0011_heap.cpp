// Lesson: Heap / Priority Queue - Max/Min element access in O(1)
// Compile: g++ -o 0011_heap 0011_heap.cpp

#include <iostream>
#include <queue>
#include <vector>

int main() {
  // 1. Max Heap (Default)
  std::priority_queue<int> maxHeap;

  std::cout << "Pushing 10, 30, 20, 5 to Max Heap...\n";
  maxHeap.push(10);
  maxHeap.push(30);
  maxHeap.push(20);
  maxHeap.push(5);

  std::cout << "Max element (top): " << maxHeap.top() << "\n";

  // 2. Min Heap
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  std::cout << "\nPushing 10, 30, 20, 5 to Min Heap...\n";
  minHeap.push(10);
  minHeap.push(30);
  minHeap.push(20);
  minHeap.push(5);

  std::cout << "Min element (top): " << minHeap.top() << "\n";

  // Popping Max Heap
  std::cout << "\nPopping all from Max Heap: ";
  while (!maxHeap.empty()) {
    std::cout << maxHeap.top() << " ";
    maxHeap.pop();
  }
  std::cout << "\n";

  return 0;
}
