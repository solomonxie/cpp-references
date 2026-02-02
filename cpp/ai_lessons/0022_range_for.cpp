// Lesson: Range-based for (auto x : range)
// Compile: g++ -o 0022_range_for 0022_range_for.cpp

#include <iostream>
#include <vector>
#include <array>

int main() {
    std::vector<int> v = {10, 20, 30};
    std::cout << "vector: ";
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "by reference (modify): ";
    for (auto& x : v) {
        x *= 2;
    }
    for (auto x : v) std::cout << x << " ";
    std::cout << "\n";

    std::array<int, 3> a = {1, 2, 3};
    std::cout << "array: ";
    for (auto x : a) std::cout << x << " ";
    std::cout << "\n";

    std::string s = "hi";
    std::cout << "string: ";
    for (char c : s) std::cout << c << " ";
    std::cout << "\n";
    return 0;
}
