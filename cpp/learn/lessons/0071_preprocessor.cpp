// Lesson: #define, #ifdef, #if, macros caveats
// Compile: g++ -o 0071_preprocessor 0071_preprocessor.cpp

#include <iostream>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))  // parentheses matter: SQUARE(a+1) -> (a+1)*(a+1)

#ifdef PI
#define HAS_PI
#endif

#ifndef NDEBUG
#define DEBUG_MSG(msg) std::cout << "Debug: " << msg << "\n"
#else
#define DEBUG_MSG(msg)
#endif

int main() {
    std::cout << "PI = " << PI << "\n";
    std::cout << "SQUARE(5) = " << SQUARE(5) << "\n";
    std::cout << "SQUARE(2+3) = " << SQUARE(2+3) << "\n";

    DEBUG_MSG("running");

#if 1
    std::cout << "This block is compiled\n";
#endif
    return 0;
}
