// Lesson: typedef, using for type aliases
// Compile: g++ -o 0072_typedef_using 0072_typedef_using.cpp -std=c++11

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef unsigned long ulong;
typedef std::vector<int> IntVec;

using DoubleVec = std::vector<double>;   // C++11: preferred for aliases
using StringMap = std::map<std::string, std::string>;

int main() {
    ulong u = 100;
    IntVec v = {1, 2, 3};
    DoubleVec d = {1.0, 2.0};

    std::cout << "ulong u = " << u << "\n";
    std::cout << "IntVec size = " << v.size() << "\n";
    std::cout << "DoubleVec size = " << d.size() << "\n";
    return 0;
}
