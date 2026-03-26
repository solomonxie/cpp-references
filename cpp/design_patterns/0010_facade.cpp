/**
 * Facade Pattern
 * 
 * Provides a simplified interface to a library, a framework, or any other
 * complex set of classes.
 */
#include <iostream>
#include <string>

class CPU {
public:
    void freeze() { std::cout << "CPU: Freeze" << std::endl; }
    void jump(long position) { std::cout << "CPU: Jump to " << position << std::endl; }
    void execute() { std::cout << "CPU: Execute" << std::endl; }
};

class Memory {
public:
    void load(long position, std::string data) { std::cout << "Memory: Load '" << data << "' at " << position << std::endl; }
};

class HardDrive {
public:
    std::string read(long lba, int size) { return "Data from Sector " + std::to_string(lba); }
};

class ComputerFacade {
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
public:
    void start() {
        cpu.freeze();
        memory.load(0, hardDrive.read(100, 1024));
        cpu.jump(0);
        cpu.execute();
    }
};

int main() {
    ComputerFacade computer;
    computer.start();
    return 0;
}
