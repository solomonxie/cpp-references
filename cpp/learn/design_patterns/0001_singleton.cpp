/**
 * Singleton Pattern
 * 
 * Ensures a class has only one instance and provides a global point of access to it.
 * It is often used for logging, driver objects, caching, and thread pools.
 */
#include <iostream>
#include <string>

class Singleton {
private:
    static Singleton* instance;
    std::string data;

    // Private constructor to prevent instantiation
    Singleton() : data("Singleton Instance") {}

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        std::cout << data << " is working." << std::endl;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    if (s1 == s2) {
        std::cout << "Both instances are the same." << std::endl;
    }

    return 0;
}
