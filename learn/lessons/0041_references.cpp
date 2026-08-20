// Lesson: References, binding, no null reference
// Compile: g++ -o 0041_references 0041_references.cpp

#include <iostream>

int main() {
    int x = 42;
    int& r = x;   // r is an alias for x (must bind to valid object)

    std::cout << "x = " << x << " r = " << r << "\n";
    r = 100;      // modifies x
    std::cout << "after r = 100: x = " << x << "\n";

    // int& bad;     // error: reference must be initialized
    // int& null_ref = nullptr;  // error: no null reference

    const int& cr = x;  // const reference: can read, cannot modify through cr
    std::cout << "cr = " << cr << "\n";
    return 0;
}
