// Lesson: Static Array - Fixed-size contiguous memory collection
// Compile: g++ -o 0001_array 0001_array.cpp

#include <iostream>
#include <array> // For std::array (modern C++ alternative to C-style arrays)

int main() {
    // 1. C-style Array (Primitive)
    // Fixed size determined at compile time
    int c_arr[5] = {10, 20, 30, 40, 50};

    std::cout << "--- C-style Array ---\n";
    std::cout << "Element at index 2: " << c_arr[2] << "\n";
    
    // Iterating using a loop
    for (int i = 0; i < 5; ++i) {
        std::cout << "Index [" << i << "]: " << c_arr[i] << "\n";
    }

    // 2. Modern C++ Array (std::array)
    // Safer, provides size() and other container-like features
    std::array<int, 3> modern_arr = {1, 2, 3};

    std::cout << "\n--- std::array ---\n";
    std::cout << "Size: " << modern_arr.size() << "\n";
    std::cout << "First element: " << modern_arr.front() << "\n";
    std::cout << "Last element: " << modern_arr.back() << "\n";

    // Range-based for loop
    for (const auto& val : modern_arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
