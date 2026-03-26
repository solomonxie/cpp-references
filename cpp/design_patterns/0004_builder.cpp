/**
 * Builder Pattern
 * 
 * Separates the construction of a complex object from its representation,
 * allowing the same construction process to create different representations.
 */
#include <iostream>
#include <string>
#include <vector>

class Computer {
public:
    std::string cpu;
    std::string ram;
    std::string storage;

    void display() {
        std::cout << "Computer [CPU: " << cpu << ", RAM: " << ram << ", Storage: " << storage << "]" << std::endl;
    }
};

class ComputerBuilder {
private:
    Computer* computer;
public:
    ComputerBuilder() { computer = new Computer(); }
    ~ComputerBuilder() { delete computer; }

    ComputerBuilder* setCPU(std::string cpu) {
        computer->cpu = cpu;
        return this;
    }

    ComputerBuilder* setRAM(std::string ram) {
        computer->ram = ram;
        return this;
    }

    ComputerBuilder* setStorage(std::string storage) {
        computer->storage = storage;
        return this;
    }

    Computer* build() {
        return computer;
    }
};

int main() {
    ComputerBuilder builder;
    Computer* myPC = builder.setCPU("Intel i9")
                             ->setRAM("32GB")
                             ->setStorage("1TB SSD")
                             ->build();
    
    myPC->display();

    return 0;
}
