// Lesson: Implicit conversion, static_cast
// Compile: g++ -o 0010_type_conversion 0010_type_conversion.cpp

#include <iostream>

int main() {
    // Implicit conversions
    int i = 3;
    double d = i;      // int -> double
    std::cout << "int 3 -> double " << d << "\n";

    double e = 3.9;
    int j = e;         // double -> int (truncation)
    std::cout << "double 3.9 -> int " << j << "\n";

    // Explicit cast: static_cast<Type>(value)
    double f = 5.7;
    int k = static_cast<int>(f);
    std::cout << "static_cast<int>(5.7) = " << k << "\n";

    unsigned u = 42;
    int neg = -1;
    std::cout << "unsigned 42 + int -1 (implicit) = " << (u + neg) << "\n";  // careful with signed/unsigned
    return 0;
}
