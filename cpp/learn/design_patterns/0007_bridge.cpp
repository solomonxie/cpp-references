/**
 * Bridge Pattern
 * 
 * Splits a large class or a set of closely related classes into two separate
 * hierarchies—abstraction and implementation—which can be developed independently.
 */
#include <iostream>
#include <string>

// Implementation Interface
class Device {
public:
    virtual ~Device() {}
    virtual bool isEnabled() const = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;
};

// Concrete Implementations
class TV : public Device {
    bool on = false;
public:
    bool isEnabled() const override { return on; }
    void enable() override { on = true; std::cout << "TV is ON" << std::endl; }
    void disable() override { on = false; std::cout << "TV is OFF" << std::endl; }
};

class Radio : public Device {
    bool on = false;
public:
    bool isEnabled() const override { return on; }
    void enable() override { on = true; std::cout << "Radio is ON" << std::endl; }
    void disable() override { on = false; std::cout << "Radio is OFF" << std::endl; }
};

// Abstraction
class RemoteControl {
protected:
    Device* device;
public:
    RemoteControl(Device* d) : device(d) {}
    virtual ~RemoteControl() {}
    void togglePower() {
        if (device->isEnabled()) device->disable();
        else device->enable();
    }
};

// Refined Abstraction
class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(Device* d) : RemoteControl(d) {}
    void mute() { std::cout << "Device muted" << std::endl; }
};

int main() {
    TV tv;
    RemoteControl remote(&tv);
    remote.togglePower();

    Radio radio;
    AdvancedRemoteControl advRemote(&radio);
    advRemote.togglePower();
    advRemote.mute();

    return 0;
}
