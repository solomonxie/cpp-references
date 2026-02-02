// Lesson: + - * / %, precedence, integer vs float division
// Compile: g++ -o 0005_operators_arithmetic 0005_operators_arithmetic.cpp

#include <iostream>

int main() {
    int a = 17, b = 5;
    std::cout << "a=" << a << " b=" << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << " (integer division)\n";
    std::cout << "a % b = " << (a % b) << " (remainder)\n";

    double x = 17.0, y = 5.0;
    std::cout << "17.0 / 5.0 = " << (x / y) << " (float division)\n";

    // Precedence: * / % before + -
    std::cout << "2 + 3 * 4 = " << (2 + 3 * 4) << "\n";
    return 0;
}
