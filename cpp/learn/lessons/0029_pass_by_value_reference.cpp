// Lesson: Value vs reference parameters
// Compile: g++ -o 0029_pass_by_value_reference 0029_pass_by_value_reference.cpp

#include <iostream>

void by_value(int x) {
    x = 100;  // only local copy changes
}

void by_reference(int& x) {
    x = 100;  // original variable changes
}

void by_const_reference(const int& x) {
    // x = 100;  // error: cannot modify
    std::cout << "read-only: " << x << "\n";
}

int main() {
    int a = 10;
    by_value(a);
    std::cout << "after by_value: a = " << a << "\n";  // still 10

    by_reference(a);
    std::cout << "after by_reference: a = " << a << "\n";  // 100

    by_const_reference(a);  // no copy, read-only
    return 0;
}
