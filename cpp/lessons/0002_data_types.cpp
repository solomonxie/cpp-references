// Lesson: int, double, bool, char, size_t
// Compile: g++ -o 0002_data_types 0002_data_types.cpp

#include <iostream>
#include <cstddef>

int main() {
    int i = -42;
    double d = 3.14159;
    bool b = true;
    char c = 'A';
    size_t sz = 100;  // unsigned type for sizes (e.g. array size)

    std::cout << "int:    " << i << "\n";
    std::cout << "double: " << d << "\n";
    std::cout << "bool:   " << b << " (1=true, 0=false)\n";
    std::cout << "char:   " << c << " ('" << c << "')\n";
    std::cout << "size_t: " << sz << "\n";
    return 0;
}
