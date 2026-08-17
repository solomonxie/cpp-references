// Lesson: Pointer arithmetic, array relationship
// Compile: g++ -o 0040_pointers_arithmetic 0040_pointers_arithmetic.cpp

#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;  // p points to arr[0]

    std::cout << "*p = " << *p << " (arr[0])\n";
    std::cout << "*(p+1) = " << *(p + 1) << " (arr[1])\n";
    std::cout << "*(p+2) = " << *(p + 2) << "\n";

    p++;  // advance to next element
    std::cout << "after p++: *p = " << *p << "\n";

    int* end = arr + 5;
    std::cout << "iterate with pointer: ";
    for (int* it = arr; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}
