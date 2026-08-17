// Lesson: inline functions
// Compile: g++ -o 0028_inline 0028_inline.cpp

#include <iostream>

// inline: hint to compiler to paste body at call site (avoid function call overhead)
inline int square(int x) {
    return x * x;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "square(5) = " << square(5) << "\n";
    std::cout << "max(10, 20) = " << max(10, 20) << "\n";
    return 0;
}
