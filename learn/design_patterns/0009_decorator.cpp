/**
 * Decorator Pattern
 * 
 * Lets you attach new behaviors to objects by placing these objects inside
 * special wrapper objects that contain the behaviors.
 */
#include <iostream>
#include <string>
#include <memory>

class Coffee {
public:
    virtual ~Coffee() {}
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override { return "Simple Coffee"; }
    double cost() const override { return 1.0; }
};

class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override { return coffee->getDescription() + ", Milk"; }
    double cost() const override { return coffee->cost() + 0.5; }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override { return coffee->getDescription() + ", Sugar"; }
    double cost() const override { return coffee->cost() + 0.2; }
};

int main() {
    std::unique_ptr<Coffee> myCoffee = std::make_unique<SimpleCoffee>();
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << std::endl;

    myCoffee = std::make_unique<MilkDecorator>(std::move(myCoffee));
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << std::endl;

    myCoffee = std::make_unique<SugarDecorator>(std::move(myCoffee));
    std::cout << myCoffee->getDescription() << " costs $" << myCoffee->cost() << std::endl;

    return 0;
}
