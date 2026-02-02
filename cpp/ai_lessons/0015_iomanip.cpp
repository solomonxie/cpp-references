// Lesson: setw, setprecision, fixed, left/right
// Compile: g++ -o 0015_iomanip 0015_iomanip.cpp

#include <iostream>
#include <iomanip>

int main() {
    int a = 42, b = 1234, c = 7;
    std::cout << "Default: " << a << " " << b << " " << c << "\n";
    std::cout << "setw(6): " << std::setw(6) << a << std::setw(6) << b << std::setw(6) << c << "\n";

    double pi = 3.14159265359;
    std::cout << "Default: " << pi << "\n";
    std::cout << "setprecision(4): " << std::setprecision(4) << pi << "\n";
    std::cout << "fixed + setprecision(2): " << std::fixed << std::setprecision(2) << pi << "\n";

    std::cout << "left setw(8): " << std::left << std::setw(8) << "hi"
              << "|\n";
    std::cout << "right setw(8): " << std::right << std::setw(8) << "hi"
              << "|\n";
    return 0;
}
