// Lesson: Rvalue reference, std::move, move constructor/assignment
// Compile: g++ -o 0073_move_semantics 0073_move_semantics.cpp -std=c++11

#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main() {
    std::string s1 = "hello";
    std::string s2 = std::move(s1);  // s1's resources moved to s2; s1 is valid but unspecified
    std::cout << "s2 after move: " << s2 << "\n";

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1);
    std::cout << "v2 size after move: " << v2.size() << "\n";
    std::cout << "v1 size after move: " << v1.size() << " (typically 0)\n";
    return 0;
}
