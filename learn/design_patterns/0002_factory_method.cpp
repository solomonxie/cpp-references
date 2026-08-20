/**
 * Factory Method Pattern
 * 
 * Defines an interface for creating an object, but lets subclasses decide which class to instantiate.
 * This pattern lets a class defer instantiation to subclasses.
 */
#include <iostream>
#include <memory>
#include <string>

// Product Interface
class Product {
public:
    virtual ~Product() {}
    virtual std::string getName() const = 0;
};

// Concrete Products
class ConcreteProductA : public Product {
public:
    std::string getName() const override { return "Product A"; }
};

class ConcreteProductB : public Product {
public:
    std::string getName() const override { return "Product B"; }
};

// Creator (Factory)
class Creator {
public:
    virtual ~Creator() {}
    virtual std::unique_ptr<Product> createProduct() const = 0;

    void someOperation() const {
        auto product = createProduct();
        std::cout << "Creator: Working with " << product->getName() << std::endl;
    }
};

// Concrete Creators
class CreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

class CreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    std::unique_ptr<Creator> creatorA = std::make_unique<CreatorA>();
    creatorA->someOperation();

    std::unique_ptr<Creator> creatorB = std::make_unique<CreatorB>();
    creatorB->someOperation();

    return 0;
}
