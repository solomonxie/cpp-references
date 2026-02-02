// Lesson: C-style arrays, size, indexing
// Compile: g++ -o 0032_array_cstyle 0032_array_cstyle.cpp

#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int arr2[] = {1, 2, 3};  // size 3 inferred

    std::cout << "arr[0] = " << arr[0] << ", arr[2] = " << arr[2] << "\n";

    for (size_t i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    // Size in bytes / size of element = number of elements
    size_t n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "sizeof(arr)/sizeof(arr[0]) = " << n << "\n";
    return 0;
}
