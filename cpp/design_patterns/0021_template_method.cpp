/**
 * Template Method Pattern
 * 
 * Defines the skeleton of an algorithm in the superclass but lets
 * subclasses override specific steps of the algorithm without changing
 * its structure.
 */
#include <iostream>

class AbstractClass {
public:
    void templateMethod() const {
        baseOperation1();
        requiredOperations1();
        baseOperation2();
        hook1();
        requiredOperation2();
        baseOperation3();
        hook2();
    }
protected:
    void baseOperation1() const { std::cout << "AbstractClass: baseOperation1\n"; }
    void baseOperation2() const { std::cout << "AbstractClass: baseOperation2\n"; }
    void baseOperation3() const { std::cout << "AbstractClass: baseOperation3\n"; }
    virtual void requiredOperations1() const = 0;
    virtual void requiredOperation2() const = 0;
    virtual void hook1() const {}
    virtual void hook2() const {}
};

class ConcreteClass1 : public AbstractClass {
protected:
    void requiredOperations1() const override { std::cout << "ConcreteClass1: requiredOperations1\n"; }
    void requiredOperation2() const override { std::cout << "ConcreteClass1: requiredOperation2\n"; }
};

class ConcreteClass2 : public AbstractClass {
protected:
    void requiredOperations1() const override { std::cout << "ConcreteClass2: requiredOperations1\n"; }
    void requiredOperation2() const override { std::cout << "ConcreteClass2: requiredOperation2\n"; }
    void hook1() const override { std::cout << "ConcreteClass2: hook1 (overridden)\n"; }
};

int main() {
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass1 c1;
    c1.templateMethod();
    std::cout << "\n";
    ConcreteClass2 c2;
    c2.templateMethod();
    return 0;
}
