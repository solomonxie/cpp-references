/**
 * Visitor Pattern
 * 
 * Lets you separate algorithms from the objects on which they operate.
 */
#include <iostream>
#include <vector>

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
public:
    virtual void visitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void visitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};

class Component {
public:
    virtual ~Component() {}
    virtual void accept(Visitor* visitor) const = 0;
};

class ConcreteComponentA : public Component {
public:
    void accept(Visitor* visitor) const override { visitor->visitConcreteComponentA(this); }
    std::string exclusiveMethodA() const { return "A"; }
};

class ConcreteComponentB : public Component {
public:
    void accept(Visitor* visitor) const override { visitor->visitConcreteComponentB(this); }
    std::string specialMethodB() const { return "B"; }
};

class ConcreteVisitor1 : public Visitor {
public:
    void visitConcreteComponentA(const ConcreteComponentA* element) const override {
        std::cout << element->exclusiveMethodA() << " + ConcreteVisitor1\n";
    }
    void visitConcreteComponentB(const ConcreteComponentB* element) const override {
        std::cout << element->specialMethodB() << " + ConcreteVisitor1\n";
    }
};

int main() {
    std::vector<Component*> components = {new ConcreteComponentA, new ConcreteComponentB};
    ConcreteVisitor1* v1 = new ConcreteVisitor1;
    for (const auto& comp : components) comp->accept(v1);

    for (const auto& comp : components) delete comp;
    delete v1;
    return 0;
}
