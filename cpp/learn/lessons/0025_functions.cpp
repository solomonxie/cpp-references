// Lesson: Function declaration, definition, call, return
// Compile: g++ -o 0025_functions 0025_functions.cpp

#include <iostream>

// Declaration (optional if definition appears before use)
int add(int a, int b);

// Definition
int add(int a, int b) {
    return a + b;
}

void greet() {
    std::cout << "Hello!\n";
}

int main() {
    int sum = add(3, 4);
    std::cout << "add(3, 4) = " << sum << "\n";
    greet();
    return 0;
}
