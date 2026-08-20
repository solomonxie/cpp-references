// Lesson: if / else if / else
// Compile: g++ -o 0018_if_else 0018_if_else.cpp

#include <iostream>

int main() {
    int x = 10;

    if (x > 20) {
        std::cout << "x > 20\n";
    } else if (x > 5) {
        std::cout << "x > 5 and x <= 20\n";
    } else {
        std::cout << "x <= 5\n";
    }

    if (x == 10)
        std::cout << "x is 10 (single statement, braces optional)\n";

    return 0;
}
