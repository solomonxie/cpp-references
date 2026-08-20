// Lesson: namespace, using, std::
// Compile: g++ -o 0012_namespace 0012_namespace.cpp

#include <iostream>

namespace mylib {
    int value = 42;
    void greet() { std::cout << "Hello from mylib\n"; }
}

namespace other {
    int value = 100;
}

int main() {
    std::cout << "std::cout from standard namespace\n";

    std::cout << "mylib::value = " << mylib::value << "\n";
    std::cout << "other::value = " << other::value << "\n";
    mylib::greet();

    using mylib::value;
    std::cout << "After using mylib::value: value = " << value << "\n";

    using namespace other;  // brings all of other into scope (use sparingly)
    std::cout << "other::value (via using namespace) = " << other::value << "\n";
    return 0;
}
