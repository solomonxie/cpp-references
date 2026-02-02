// Lesson: && || !, short-circuit evaluation
// Compile: g++ -o 0007_operators_logical 0007_operators_logical.cpp

#include <iostream>

bool side_effect() {
    std::cout << "  side_effect() called\n";
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "true && false = " << (true && false) << "\n";
    std::cout << "true || false = " << (true || false) << "\n";
    std::cout << "!true = " << (!true) << "\n";

    std::cout << "Short-circuit: false && side_effect() -> ";
    bool a = (false && side_effect());  // side_effect() not called
    std::cout << a << "\n";

    std::cout << "Short-circuit: true || side_effect() -> ";
    bool b = (true || side_effect());   // side_effect() not called
    std::cout << b << "\n";
    return 0;
}
