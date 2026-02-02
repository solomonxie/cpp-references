// Lesson: Base/derived, public inheritance
// Compile: g++ -o 0049_inheritance 0049_inheritance.cpp

#include <iostream>
#include <string>

class Animal {
public:
    std::string name;
    void speak() const { std::cout << name << " makes a sound\n"; }
};

class Dog : public Animal {
public:
    void speak() const { std::cout << name << " says woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const { std::cout << name << " says meow\n"; }
};

int main() {
    Dog d;
    d.name = "Rex";
    d.speak();

    Cat c;
    c.name = "Felix";
    c.speak();

    Animal* a = &d;
    a->speak();  // "makes a sound" (not overridden without virtual)
    return 0;
}
