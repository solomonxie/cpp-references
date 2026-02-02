// Lesson: Destructor ~Class(), RAII idea
// Compile: g++ -o 0047_destructor 0047_destructor.cpp

#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
};

class Wrapper {
    Resource* r_;
public:
    Wrapper() : r_(new Resource()) {}
    ~Wrapper() {
        delete r_;
        std::cout << "Wrapper destroyed\n";
    }
};

int main() {
    {
        Resource r;
        std::cout << "inside block\n";
    }
    std::cout << "after block (r destroyed)\n";

    {
        Wrapper w;
    }
    std::cout << "after Wrapper block\n";
    return 0;
}
