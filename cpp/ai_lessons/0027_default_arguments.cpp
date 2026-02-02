// Lesson: Default parameter values
// Compile: g++ -o 0027_default_arguments 0027_default_arguments.cpp

#include <iostream>
#include <string>

void greet(const std::string& name, int times = 1) {
    for (int i = 0; i < times; ++i) {
        std::cout << "Hello, " << name << "!\n";
    }
}

int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

int main() {
    greet("Alice");           // times defaults to 1
    greet("Bob", 2);          // times = 2

    std::cout << "power(3) = " << power(3) << "\n";      // exp defaults to 2 -> 9
    std::cout << "power(3, 3) = " << power(3, 3) << "\n"; // 27
    return 0;
}
