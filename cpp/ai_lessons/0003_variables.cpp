// Lesson: Declaration, definition, initialization, auto
// Compile: g++ -o 0003_variables 0003_variables.cpp -std=c++17

#include <iostream>
#include <string>

int main() {
    int x;           // declaration (uninitialized)
    int y = 10;      // definition with copy initialization
    int z{20};       // definition with brace initialization (C++11)
    auto a = 42;     // type deduced as int
    auto s = std::string("hello");  // type deduced as std::string

    x = 5;           // assignment
    std::cout << "x=" << x << " y=" << y << " z=" << z << "\n";
    std::cout << "auto a=" << a << " auto s=" << s << "\n";
    return 0;
}
