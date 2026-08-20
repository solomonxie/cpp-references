// Lesson: #ifndef/#define/#endif or #pragma once
// Compile: g++ -o 0075_include_guards 0075_include_guards.cpp 0075_demo.cpp

#include <iostream>
#include "0075_demo.h"

int main() {
    std::cout << "get_value_0075() = " << get_value_0075() << "\n";
    return 0;
}
