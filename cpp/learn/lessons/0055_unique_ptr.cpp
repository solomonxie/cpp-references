// Lesson: std::unique_ptr, ownership, make_unique
// Compile: g++ -o 0055_unique_ptr 0055_unique_ptr.cpp -std=c++14

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p1(new int(42));
    std::cout << "*p1 = " << *p1 << "\n";

    auto p2 = std::make_unique<int>(100);  // preferred
    std::cout << "*p2 = " << *p2 << "\n";

    // p1.get() raw pointer; p1.release() relinquish ownership
    std::unique_ptr<int> p3 = std::move(p2);  // p2 is now null, p3 owns
    std::cout << "after move: p2 is " << (p2 ? "valid" : "null")
              << ", *p3 = " << *p3 << "\n";

    // No copy; only move. Destructor calls delete automatically.
    return 0;
}
