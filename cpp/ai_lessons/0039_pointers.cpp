// Lesson: Pointer declaration, & address-of, * dereference
// Compile: g++ -o 0039_pointers 0039_pointers.cpp

#include <iostream>

int main() {
    int x = 42;
    int* p = &x;   // p points to x (& = address-of)

    std::cout << "x = " << x << "\n";
    std::cout << "&x = " << &x << " (address)\n";
    std::cout << "p = " << p << " (same address)\n";
    std::cout << "*p = " << *p << " (dereference: value at p)\n";

    *p = 100;      // modify x through p
    std::cout << "after *p = 100: x = " << x << "\n";

    int* q = nullptr;  // null pointer
    std::cout << "q = nullptr\n";
    return 0;
}
