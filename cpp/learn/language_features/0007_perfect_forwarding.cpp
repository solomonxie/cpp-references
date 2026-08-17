/**
 * 0007_perfect_forwarding.cpp
 * 
 * Demonstrates Perfect Forwarding using forwarding references 
 * (T&&) and std::forward to preserve value categories (lvalue/rvalue).
 */
#include <iostream>
#include <utility>

void process(int& i) { std::cout << "Lvalue process: " << i << std::endl; }
void process(int&& i) { std::cout << "Rvalue process: " << i << std::endl; }

// Template with Perfect Forwarding
template <typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg));
}

int main() {
    int x = 10;

    std::cout << "Passing lvalue to wrapper:" << std::endl;
    wrapper(x); // arg is Lvalue reference, std::forward preserves it

    std::cout << "\nPassing rvalue to wrapper:" << std::endl;
    wrapper(20); // arg is Rvalue reference, std::forward preserves it

    return 0;
}
