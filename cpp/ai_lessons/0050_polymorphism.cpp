// Lesson: virtual, override, base pointer to derived
// Compile: g++ -o 0050_polymorphism 0050_polymorphism.cpp

#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    virtual void speak() const { std::cout << name << " makes a sound\n"; }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << name << " says woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << name << " says meow\n"; }
};

int main() {
    Dog d;
    d.name = "Rex";

    Animal* a = &d;
    a->speak();  // "says woof" (virtual dispatch)

    Cat c;
    c.name = "Felix";
    Animal* a2 = &c;
    a2->speak();  // "says meow"
    return 0;
}
