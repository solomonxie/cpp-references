// Lesson: switch, case, break, default
// Compile: g++ -o 0019_switch 0019_switch.cpp

#include <iostream>

int main() {
    int choice = 2;

    switch (choice) {
        case 1:
            std::cout << "One\n";
            break;
        case 2:
            std::cout << "Two\n";
            break;
        case 3:
            std::cout << "Three\n";
            break;
        default:
            std::cout << "Other\n";
            break;
    }

    // Without break, execution falls through to next case
    int c = 1;
    switch (c) {
        case 1:
            std::cout << "case 1 ";
        case 2:
            std::cout << "case 2 ";
        case 3:
            std::cout << "case 3\n";
            break;
        default:
            break;
    }
    return 0;
}
