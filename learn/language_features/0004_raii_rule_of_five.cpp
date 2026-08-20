/**
 * 0004_raii_rule_of_five.cpp
 * 
 * Demonstrates RAII (Resource Acquisition Is Initialization) and
 * the Rule of Five (Destructor, Copy Constructor, Copy Assignment, 
 * Move Constructor, Move Assignment).
 */
#include <iostream>
#include <algorithm>
#include <cstring>

class ResourceManager {
private:
    char* resource;
    size_t size;

public:
    // Constructor (RAII: Acquire resource)
    ResourceManager(const char* data) {
        size = std::strlen(data);
        resource = new char[size + 1];
        std::strcpy(resource, data);
        std::cout << "Constructed: " << resource << std::endl;
    }

    // 1. Destructor (RAII: Release resource)
    ~ResourceManager() {
        if (resource) {
            std::cout << "Destructing: " << resource << std::endl;
            delete[] resource;
        }
    }

    // 2. Copy Constructor
    ResourceManager(const ResourceManager& other) {
        size = other.size;
        resource = new char[size + 1];
        std::strcpy(resource, other.resource);
        std::cout << "Copy Constructed: " << resource << std::endl;
    }

    // 3. Copy Assignment Operator
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete[] resource;
            size = other.size;
            resource = new char[size + 1];
            std::strcpy(resource, other.resource);
            std::cout << "Copy Assigned: " << resource << std::endl;
        }
        return *this;
    }

    // 4. Move Constructor
    ResourceManager(ResourceManager&& other) noexcept : resource(nullptr), size(0) {
        resource = other.resource;
        size = other.size;
        other.resource = nullptr;
        other.size = 0;
        std::cout << "Move Constructed" << std::endl;
    }

    // 5. Move Assignment Operator
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            delete[] resource;
            resource = other.resource;
            size = other.size;
            other.resource = nullptr;
            other.size = 0;
            std::cout << "Move Assigned" << std::endl;
        }
        return *this;
    }
};

int main() {
    ResourceManager res1("Hello");
    ResourceManager res2 = res1; // Copy
    ResourceManager res3 = std::move(res1); // Move

    return 0;
}
