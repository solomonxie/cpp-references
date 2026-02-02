// Lesson: std::weak_ptr, breaking cycles
// Compile: g++ -o 0057_weak_ptr 0057_weak_ptr.cpp -std=c++11

#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;  // does not increase use_count

    std::cout << "sp.use_count() = " << sp.use_count() << "\n";

    if (!wp.expired()) {
        std::shared_ptr<int> sp2 = wp.lock();  // get shared_ptr if still valid
        if (sp2) std::cout << "*sp2 = " << *sp2 << "\n";
    }

    sp.reset();
    std::cout << "after sp.reset(): wp.expired() = " << wp.expired() << "\n";

    std::shared_ptr<int> sp3 = wp.lock();
    std::cout << "wp.lock() returns " << (sp3 ? "valid" : "null") << "\n";
    return 0;
}
