// Lesson: Forward declare class/function to reduce includes
// Compile: g++ -o 0076_forward_declaration 0076_forward_declaration.cpp

#include <iostream>

class Bar;  // forward declaration: no need to include full definition yet

void use_bar(Bar* b);  // can declare function taking Bar*

class Bar {
public:
    int value = 42;
};

void use_bar(Bar* b) {
    if (b) std::cout << "Bar::value = " << b->value << "\n";
}

int main() {
    Bar b;
    use_bar(&b);
    return 0;
}
