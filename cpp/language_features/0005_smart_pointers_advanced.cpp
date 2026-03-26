/**
 * 0005_smart_pointers_advanced.cpp
 * 
 * Demonstrates advanced smart pointer usage:
 * 1. std::unique_ptr with custom deleter.
 * 2. std::shared_ptr with custom deleter.
 * 3. std::weak_ptr for breaking circular references.
 */
#include <iostream>
#include <memory>
#include <cstdio>

struct FileDeleter {
    void operator()(FILE* f) const {
        if (f) {
            std::cout << "Closing file..." << std::endl;
            fclose(f);
        }
    }
};

class B; // Forward declaration
class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destructed" << std::endl; }
};

class B {
public:
    std::weak_ptr<A> a_ptr; // weak_ptr to break cycle
    ~B() { std::cout << "B destructed" << std::endl; }
};

int main() {
    // 1. Unique pointer with custom deleter (lambda)
    std::unique_ptr<int, void(*)(int*)> u_ptr(new int(10), [](int* p) {
        std::cout << "Custom deleting unique_ptr resource: " << *p << std::endl;
        delete p;
    });

    // 2. Shared pointer with custom deleter (struct)
    // Using nullptr for FILE* just to show the deleter pattern
    std::shared_ptr<FILE> s_ptr(nullptr, FileDeleter());

    // 3. Weak Pointer breaking circular reference
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a; // Cycles would prevent destruction if this was shared_ptr

    std::cout << "A and B created with weak_ptr link." << std::endl;

    return 0;
}
