// Lesson: Ternary operator ? :
// Compile: g++ -o 0024_ternary 0024_ternary.cpp

#include <iostream>
#include <string>

int main() {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    std::cout << "max(" << a << "," << b << ") = " << max << "\n";

    int x = 5;
    std::cout << (x % 2 == 0 ? "even" : "odd") << "\n";

    bool positive = (x > 0);
    std::string sign = positive ? "positive" : "non-positive";
    std::cout << "x is " << sign << "\n";

    // Nested ternary (use sparingly)
    int y = 0;
    std::cout << (y > 0 ? "pos" : y < 0 ? "neg" : "zero") << "\n";
    return 0;
}
