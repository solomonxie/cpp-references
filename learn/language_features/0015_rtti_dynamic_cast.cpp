/**
 * 0015_rtti_dynamic_cast.cpp
 * 
 * Demonstrates RTTI (Runtime Type Information) and 
 * dynamic_cast for safe downcasting in polymorphic hierarchies.
 */
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {} // Must be polymorphic
};

class Derived : public Base {
public:
    void derivedMethod() { std::cout << "Derived specific method." << std::endl; }
};

int main() {
    Base* b1 = new Derived();
    Base* b2 = new Base();

    // 1. typeid: Check actual runtime type
    std::cout << "b1 points to: " << typeid(*b1).name() << std::endl;
    std::cout << "b2 points to: " << typeid(*b2).name() << std::endl;

    // 2. dynamic_cast: Safe downcast
    if (Derived* d = dynamic_cast<Derived*>(b1)) {
        std::cout << "b1 successfully cast to Derived." << std::endl;
        d->derivedMethod();
    }

    if (Derived* d = dynamic_cast<Derived*>(b2)) {
        std::cout << "b2 cast success" << std::endl;
    } else {
        std::cout << "b2 failed to cast to Derived (as expected)." << std::endl;
    }

    delete b1;
    delete b2;
    return 0;
}
