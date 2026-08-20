/**
 * Command Pattern
 * 
 * Turns a request into a stand-alone object that contains all information
 * about the request. This transformation lets you pass requests as a
 * method arguments, delay or queue a request's execution, and support
 * undoable operations.
 */
#include <iostream>
#include <string>
#include <memory>

// Receiver
class Light {
public:
    void turnOn() { std::cout << "Light is ON" << std::endl; }
    void turnOff() { std::cout << "Light is OFF" << std::endl; }
};

// Command Interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

// Concrete Commands
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() const override { light->turnOn(); }
};

class LightOffCommand : public Command {
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}
    void execute() const override { light->turnOff(); }
};

// Invoker
class RemoteControl {
    std::unique_ptr<Command> command;
public:
    void setCommand(std::unique_ptr<Command> c) { command = std::move(c); }
    void pressButton() { if (command) command->execute(); }
};

int main() {
    Light light;
    RemoteControl remote;

    remote.setCommand(std::make_unique<LightOnCommand>(&light));
    remote.pressButton();

    remote.setCommand(std::make_unique<LightOffCommand>(&light));
    remote.pressButton();

    return 0;
}
