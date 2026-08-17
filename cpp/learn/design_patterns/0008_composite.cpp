/**
 * Composite Pattern
 * 
 * Lets you compose objects into tree structures and then work with these
 * structures as if they were individual objects.
 */
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Component {
public:
    virtual ~Component() {}
    virtual void execute() const = 0;
};

class Leaf : public Component {
    std::string name;
public:
    Leaf(std::string n) : name(n) {}
    void execute() const override {
        std::cout << "Leaf " << name << " executed." << std::endl;
    }
};

class Composite : public Component {
    std::vector<std::shared_ptr<Component>> children;
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }
    void execute() const override {
        std::cout << "Composite executing children:" << std::endl;
        for (const auto& child : children) {
            child->execute();
        }
    }
};

int main() {
    auto tree = std::make_shared<Composite>();
    auto branch1 = std::make_shared<Composite>();
    auto leaf1 = std::make_shared<Leaf>("1");
    auto leaf2 = std::make_shared<Leaf>("2");
    auto leaf3 = std::make_shared<Leaf>("3");

    branch1->add(leaf1);
    branch1->add(leaf2);
    tree->add(branch1);
    tree->add(leaf3);

    tree->execute();

    return 0;
}
