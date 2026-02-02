// Lesson: Function templates, type deduction
// Compile: g++ -o 0067_templates_function 0067_templates_function.cpp

#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename A, typename B>
void print_pair(A a, B b) {
    std::cout << a << " " << b << "\n";
}

int main() {
    std::cout << "add(1, 2) = " << add(1, 2) << "\n";           // T = int
    std::cout << "add(1.5, 2.5) = " << add(1.5, 2.5) << "\n";   // T = double

    print_pair(42, "hello");
    print_pair(3.14, 100);
    return 0;
}
