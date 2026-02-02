// Lesson: // and /* */, style and Doxygen
// Compile: g++ -o 0008_comments 0008_comments.cpp

#include <iostream>

// Single-line comment: everything to end of line is ignored.

/*
   Block comment: everything between /* and */ is ignored.
   Can span multiple lines.
*/

/**
 * Doxygen-style comment (for documentation generators).
 * @param x first number
 * @param y second number
 * @return sum of x and y
 */
int add(int x, int y) {
    return x + y;
}

int main() {
    int a = 3, b = 4;
    std::cout << add(a, b) << "\n";  // 7
    return 0;
}
