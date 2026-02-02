// Lesson: Default, parameterized, delegating constructors
// Compile: g++ -o 0046_constructors 0046_constructors.cpp

#include <iostream>
#include <string>

class Counter {
    int value_;
public:
    Counter() : value_(0) {}           // default
    Counter(int v) : value_(v) {}     // parameterized
    int get() const { return value_; }
};

class Greeter {
    std::string name_;
public:
    Greeter() : Greeter("world") {}   // delegating: call other ctor
    Greeter(const std::string& n) : name_(n) {}
    void say() const { std::cout << "Hello, " << name_ << "!\n"; }
};

int main() {
    Counter c1;
    Counter c2(42);
    std::cout << "c1.get() = " << c1.get() << " c2.get() = " << c2.get() << "\n";

    Greeter g1;
    Greeter g2("Alice");
    g1.say();
    g2.say();
    return 0;
}
