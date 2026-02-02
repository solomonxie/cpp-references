// Lesson: Overloading by parameter list
// Compile: g++ -o 0026_function_overload 0026_function_overload.cpp

#include <iostream>

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << "add(1, 2) = " << add(1, 2) << "\n";           // int version
    std::cout << "add(1.5, 2.5) = " << add(1.5, 2.5) << "\n";   // double version
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << "\n";     // three-arg version
    return 0;
}
