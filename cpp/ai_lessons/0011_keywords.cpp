// Lesson: Reserved keywords overview (reference-style)
// Compile: g++ -o 0011_keywords 0011_keywords.cpp

#include <iostream>

int main() {
    // C++ keywords cannot be used as identifiers (e.g. int, if, class, return).

    // Common keywords: int, double, if, else, for, while, return, class, struct,
    // public, private, virtual, const, static, namespace, using, template, try, catch, throw,
    // new, delete, true, false, nullptr, auto, and, or, not (and alternative tokens).
    bool a = true;
    bool b = false;
    if (a and b) { }   // "and" is alternative token for &&
    if (a or b)  { }   // "or" for ||
    if (not b)   { }   // "not" for !

    std::cout << "Keywords: true=" << a << " false=" << b << "\n";
    std::cout << "Use a C++ reference for the full keyword list.\n";
    return 0;
}
