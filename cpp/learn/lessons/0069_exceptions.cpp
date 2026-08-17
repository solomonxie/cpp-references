// Lesson: try/catch/throw, std::exception
// Compile: g++ -o 0069_exceptions 0069_exceptions.cpp

#include <iostream>
#include <stdexcept>
#include <string>

void might_throw(int x) {
    if (x < 0) throw std::runtime_error("x must be non-negative");
    if (x == 0) throw std::invalid_argument("x must not be zero");
    std::cout << "x = " << x << "\n";
}

int main() {
    try {
        might_throw(5);
        might_throw(-1);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try {
        might_throw(0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid: " << e.what() << "\n";
    }
    return 0;
}
