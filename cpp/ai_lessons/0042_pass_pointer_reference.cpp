// Lesson: Functions taking pointer vs reference
// Compile: g++ -o 0042_pass_pointer_reference 0042_pass_pointer_reference.cpp

#include <iostream>

void by_pointer(int* p) {
    if (p) *p = 42;  // must check for null
}

void by_reference(int& r) {
    r = 42;  // no null possible
}

void swap_pointer(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_reference(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 10;
    by_pointer(&x);
    std::cout << "after by_pointer: x = " << x << "\n";

    by_reference(x);
    std::cout << "after by_reference: x = " << x << "\n";

    int a = 1, b = 2;
    swap_reference(a, b);
    std::cout << "swap_reference: a=" << a << " b=" << b << "\n";
    swap_pointer(&a, &b);
    std::cout << "swap_pointer: a=" << a << " b=" << b << "\n";
    return 0;
}
