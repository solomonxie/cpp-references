/**
 * Proxy Pattern
 * 
 * Lets you provide a substitute or placeholder for another object.
 * A proxy controls access to the original object, allowing you to perform
 * something either before or after the request gets through to the original object.
 */
#include <iostream>
#include <string>
#include <memory>

class Subject {
public:
    virtual ~Subject() {}
    virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

class Proxy : public Subject {
private:
    std::unique_ptr<RealSubject> realSubject;
    void checkAccess() const { std::cout << "Proxy: Checking access..." << std::endl; }
    void logAccess() const { std::cout << "Proxy: Logging access..." << std::endl; }
public:
    Proxy() : realSubject(nullptr) {}
    void request() const override {
        if (realSubject == nullptr) {
            const_cast<Proxy*>(this)->realSubject = std::make_unique<RealSubject>();
        }
        checkAccess();
        realSubject->request();
        logAccess();
    }
};

int main() {
    std::cout << "Client: Executing with real subject:" << std::endl;
    RealSubject real;
    real.request();

    std::cout << "\nClient: Executing with proxy:" << std::endl;
    Proxy proxy;
    proxy.request();

    return 0;
}
