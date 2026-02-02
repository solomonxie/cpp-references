// Lesson: Multi-file .h/.hpp vs .cpp, #include
// Compile: g++ -o 0074_headers 0074_headers.cpp 0074_greeting.cpp

#include <iostream>
#include "0074_greeting.h"

int main() {
    std::cout << greet("World") << "\n";
    return 0;
}
