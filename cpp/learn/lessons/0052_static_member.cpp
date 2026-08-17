// Lesson: static data and function members
// Compile: g++ -o 0052_static_member 0052_static_member.cpp

#include <iostream>

class Counter {
    static int count_;  // one copy shared by all objects
public:
    Counter() { ++count_; }
    ~Counter() { --count_; }
    static int getCount() { return count_; }
};

int Counter::count_ = 0;  // definition (required)

int main() {
    std::cout << "count = " << Counter::getCount() << "\n";
    Counter c1;
    std::cout << "after c1: count = " << Counter::getCount() << "\n";
    {
        Counter c2, c3;
        std::cout << "after c2, c3: count = " << Counter::getCount() << "\n";
    }
    std::cout << "after block: count = " << Counter::getCount() << "\n";
    return 0;
}
