/**
 * Mediator Pattern
 * 
 * Lets you reduce chaotic dependencies between objects. The pattern restricts
 * direct communications between the objects and forces them to collaborate
 * only via a mediator object.
 */
#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
public:
    virtual void notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator;
public:
    BaseComponent(Mediator* m = nullptr) : mediator(m) {}
    void setMediator(Mediator* m) { mediator = m; }
};

class Component1 : public BaseComponent {
public:
    void doA() {
        std::cout << "Component 1 does A." << std::endl;
        mediator->notify(this, "A");
    }
    void doB() {
        std::cout << "Component 1 does B." << std::endl;
        mediator->notify(this, "B");
    }
};

class Component2 : public BaseComponent {
public:
    void doC() {
        std::cout << "Component 2 does C." << std::endl;
        mediator->notify(this, "C");
    }
    void doD() {
        std::cout << "Component 2 does D." << std::endl;
        mediator->notify(this, "D");
    }
};

class ConcreteMediator : public Mediator {
private:
    Component1* c1;
    Component2* c2;
public:
    ConcreteMediator(Component1* comp1, Component2* comp2) : c1(comp1), c2(comp2) {
        c1->setMediator(this);
        c2->setMediator(this);
    }
    void notify(BaseComponent* sender, std::string event) const override {
        if (event == "A") {
            std::cout << "Mediator reacts on A and triggers following operations:" << std::endl;
            c2->doC();
        }
        if (event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:" << std::endl;
            c1->doB();
            c2->doC();
        }
    }
};

int main() {
    Component1* c1 = new Component1;
    Component2* c2 = new Component2;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

    std::cout << "Client triggers operation A." << std::endl;
    c1->doA();

    std::cout << "\nClient triggers operation D." << std::endl;
    c2->doD();

    delete c1;
    delete c2;
    delete mediator;
    return 0;
}
