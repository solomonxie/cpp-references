// Lesson: for (init; condition; step)
// Compile: g++ -o 0020_for_loop 0020_for_loop.cpp

#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "i = " << i << "\n";
    }

    std::cout << "Countdown: ";
    for (int j = 3; j >= 0; --j) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    // Multiple variables (comma operator)
    for (int a = 0, b = 5; a < b; ++a, --b) {
        std::cout << "a=" << a << " b=" << b << "\n";
    }
    return 0;
}
