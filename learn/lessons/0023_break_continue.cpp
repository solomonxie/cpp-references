// Lesson: break, continue in loops
// Compile: g++ -o 0023_break_continue 0023_break_continue.cpp

#include <iostream>

int main() {
    std::cout << "break (exit loop when i==3): ";
    for (int i = 0; i < 6; ++i) {
        if (i == 3) break;
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "continue (skip when i==3): ";
    for (int i = 0; i < 6; ++i) {
        if (i == 3) continue;
        std::cout << i << " ";
    }
    std::cout << "\n";

    int j = 0;
    while (true) {
        ++j;
        if (j < 3) continue;
        std::cout << "while: j=" << j << "\n";
        if (j >= 5) break;
    }
    return 0;
}
