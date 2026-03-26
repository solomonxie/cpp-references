/**
 * 0006_variadic_templates.cpp
 * 
 * Demonstrates Variadic Templates (templates that take an arbitrary 
 * number of arguments) using recursion and fold expressions (C++17).
 */
#include <iostream>
#include <string>

// 1. Recursive approach (C++11)
void printAll() {
    std::cout << std::endl;
}

template <typename T, typename... Args>
void printAll(T first, Args... args) {
    std::cout << first << " ";
    printAll(args...);
}

// 2. Fold expression approach (C++17)
template <typename... Args>
void printAllFold(Args... args) {
    (std::cout << ... << (std::string(std::to_string(args)) + " ")) << std::endl;
}

// Summing using fold expressions
template <typename... Args>
auto sumAll(Args... args) {
    return (args + ...);
}

int main() {
    std::cout << "Recursive printing:" << std::endl;
    printAll(1, 2.5, "Hello", 'A');

    std::cout << "Sum using fold expression (1+2+3+4+5): " << sumAll(1, 2, 3, 4, 5) << std::endl;

    return 0;
}
