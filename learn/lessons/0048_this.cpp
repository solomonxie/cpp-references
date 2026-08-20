// Lesson: this pointer
// Compile: g++ -o 0048_this 0048_this.cpp

#include <iostream>

class Box {
    int value_;
public:
    void set(int value_) {
        this->value_ = value_;  // disambiguate: member vs parameter
    }
    int get() const {
        return this->value_;   // optional: same as value_
    }
    Box* address() {
        return this;
    }
};

int main() {
    Box b;
    b.set(42);
    std::cout << "b.get() = " << b.get() << "\n";
    std::cout << "b.address() = " << b.address() << "\n";
    return 0;
}
