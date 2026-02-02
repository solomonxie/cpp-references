// Lesson: nullptr vs NULL/0
// Compile: g++ -o 0043_nullptr 0043_nullptr.cpp -std=c++11

#include <iostream>

void f(int* p) {
    if (p == nullptr) {
        std::cout << "null pointer\n";
    } else {
        std::cout << "pointer to " << *p << "\n";
    }
}

int main() {
    int x = 42;
    int* p1 = nullptr;   // C++11: type-safe null pointer
    int* p2 = &x;

    f(p1);  // null pointer
    f(p2);  // pointer to 42

    // NULL is often 0 or (void*)0; nullptr has type std::nullptr_t
    // Prefer nullptr in C++ to avoid overload ambiguity:
    // f(0) could be f(int) or f(int*) with NULL/0
    f(nullptr);
    return 0;
}
