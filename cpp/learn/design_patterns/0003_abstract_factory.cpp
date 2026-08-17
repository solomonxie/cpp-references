/**
 * Abstract Factory Pattern
 * 
 * Provides an interface for creating families of related or dependent objects 
 * without specifying their concrete classes.
 */
#include <iostream>
#include <memory>

// Abstract Products
class Button {
public:
    virtual ~Button() {}
    virtual void paint() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() {}
    virtual void paint() const = 0;
};

// Concrete Products for Mac
class MacButton : public Button {
public:
    void paint() const override { std::cout << "Rendering Mac Button" << std::endl; }
};

class MacCheckbox : public Checkbox {
public:
    void paint() const override { std::cout << "Rendering Mac Checkbox" << std::endl; }
};

// Concrete Products for Windows
class WinButton : public Button {
public:
    void paint() const override { std::cout << "Rendering Windows Button" << std::endl; }
};

class WinCheckbox : public Checkbox {
public:
    void paint() const override { std::cout << "Rendering Windows Checkbox" << std::endl; }
};

// Abstract Factory
class GUIFactory {
public:
    virtual ~GUIFactory() {}
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

// Concrete Factories
class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<MacButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<MacCheckbox>(); }
};

class WinFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<WinButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<WinCheckbox>(); }
};

int main() {
    std::unique_ptr<GUIFactory> factory;

    // Simulate Windows environment
    std::cout << "--- Windows Style ---" << std::endl;
    factory = std::make_unique<WinFactory>();
    factory->createButton()->paint();
    factory->createCheckbox()->paint();

    // Simulate Mac environment
    std::cout << "\n--- Mac Style ---" << std::endl;
    factory = std::make_unique<MacFactory>();
    factory->createButton()->paint();
    factory->createCheckbox()->paint();

    return 0;
}
