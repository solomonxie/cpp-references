// Lesson: while, do-while
// Compile: g++ -o 0021_while_loop 0021_while_loop.cpp

#include <iostream>

int main() {
    int i = 0;
    while (i < 3) {
        std::cout << "while: i = " << i << "\n";
        ++i;
    }

    int j = 0;
    do {
        std::cout << "do-while: j = " << j << "\n";
        ++j;
    } while (j < 3);

    // do-while runs at least once (condition checked after body)
    int k = 10;
    do {
        std::cout << "do-while (k=10): runs once\n";
    } while (k < 5);
    return 0;
}
