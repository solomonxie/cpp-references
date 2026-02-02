// Lesson: Returning by value vs reference (and pitfalls)
// Compile: g++ -o 0030_return_reference 0030_return_reference.cpp

#include <iostream>
#include <string>

// Return by value: safe, copy returned
int by_value() {
    int x = 42;
    return x;  // copy
}

// Return by reference: only return reference to object that outlives the call
int global = 100;
int& get_global() {
    return global;  // OK: global lives after return
}

// DANGER: returning reference to local variable (undefined behavior)
// int& bad() { int x = 42; return x; }  // never do this

int main() {
    int a = by_value();
    std::cout << "by_value: " << a << "\n";

    int& r = get_global();
    r = 200;
    std::cout << "global after get_global() = " << global << "\n";
    return 0;
}
