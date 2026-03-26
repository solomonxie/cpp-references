/**
 * Adapter Pattern
 * 
 * Allows objects with incompatible interfaces to collaborate.
 * It wraps an object to expose a different interface that a client expects.
 */
#include <iostream>
#include <string>
#include <algorithm>

// Target interface
class Target {
public:
    virtual ~Target() {}
    virtual std::string request() const {
        return "Target: The default target's behavior.";
    }
};

// Adaptee (Incompatible interface)
class Adaptee {
public:
    std::string specificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Adapter
class Adapter : public Target {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}
    std::string request() const override {
        std::string to_reverse = adaptee->specificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

int main() {
    Target* target = new Target();
    std::cout << target->request() << std::endl;

    Adaptee* adaptee = new Adaptee();
    std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;

    Adapter* adapter = new Adapter(adaptee);
    std::cout << adapter->request() << std::endl;

    delete target;
    delete adaptee;
    delete adapter;
    return 0;
}
