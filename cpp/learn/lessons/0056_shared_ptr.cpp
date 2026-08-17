// Lesson: std::shared_ptr, make_shared, reference count
// Compile: g++ -o 0056_shared_ptr 0056_shared_ptr.cpp -std=c++11

#include <iostream>
#include <memory>

int main() {
    auto p1 = std::make_shared<int>(42);
    std::cout << "*p1 = " << *p1 << " use_count = " << p1.use_count() << "\n";

    std::shared_ptr<int> p2 = p1;  // share ownership
    std::cout << "after p2 = p1: use_count = " << p1.use_count() << "\n";

    p1.reset();  // release ownership
    std::cout << "after p1.reset(): p2.use_count() = " << p2.use_count() << "\n";

    p2.reset();  // last owner: object deleted
    std::cout << "after p2.reset(): object destroyed\n";
    return 0;
}
