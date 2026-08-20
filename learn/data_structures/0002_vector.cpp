// Lesson: Vector - Dynamic Array that can grow/shrink
// Compile: g++ -o 0002_vector 0002_vector.cpp

#include <iostream>
#include <vector>

int main() {
  // 1. Declaration and Initialization
  std::vector<int> numbers = {10, 20, 30};

  std::cout << "Initial size: " << numbers.size() << "\n";

  // 2. Adding Elements
  numbers.push_back(40); // Adds to the end
  numbers.push_back(50);

  std::cout << "After push_back, size: " << numbers.size() << "\n";
  std::cout << "Capacity: " << numbers.capacity()
            << "\n"; // Actual memory allocated

  // 3. Accessing Elements
  std::cout << "Element at index 3: " << numbers[3] << "\n";
  std::cout << "Using .at(1): " << numbers.at(1) << " (safer, checks bounds)\n";

  // 4. Modifying and Removing
  numbers[0] = 100;
  numbers.pop_back(); // Removes the last element

  std::cout << "After modifications, contents: ";
  for (int n : numbers) {
    std::cout << n << " ";
  }
  std::cout << "\n";

  // 5. Clearing
  numbers.clear();
  std::cout << "After clear, size: " << numbers.size() << "\n";

  return 0;
}
