// Lesson: const variables and const correctness
// Compile: g++ -o 0009_const 0009_const.cpp

#include <iostream>

int main() {
    const int MAX = 100;   // cannot modify MAX
    const double PI = 3.14159;

    std::cout << "MAX = " << MAX << " PI = " << PI << "\n";

    int x = 42;
    const int* p = &x;     // pointer to const: can't modify *p
    // *p = 0;  // error
    p = nullptr;           // ok: p itself is not const

    int* const q = &x;     // const pointer: can't change q
    *q = 10;               // ok: can modify *q
    // q = nullptr;        // error

    const int* const r = &x;  // const pointer to const
    std::cout << "x after *q = 10: " << x << "\n";
    return 0;
}
