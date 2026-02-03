// Lesson: == != < > <= >=, result type bool
// Compile: g++ -o 0006_operators_comparison 0006_operators_comparison.cpp

#include <iostream>

int main() {
    int a = 10, b = 20;
    std::cout << std::boolalpha;  // print true/false instead of 1/0
    std::cout << "a == b  " << (a == b) << "\n";
    std::cout << "a != b  " << (a != b) << "\n";
    std::cout << "a < b   " << (a < b) << "\n";
    std::cout << "a > b   " << (a > b) << "\n";
    std::cout << "a <= b  " << (a <= b) << "\n";
    std::cout << "a >= b  " << (a >= b) << "\n";

    bool result = (a < b);  // comparison yields bool
    std::cout << "result (a < b) = " << result << "\n";
    return 0;
}
