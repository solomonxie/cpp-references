/**
 * 0009_concepts.cpp
 * 
 * Demonstrates C++20 Concepts, which provide a more readable 
 * way to constrain template arguments compared to SFINAE.
 */
#include <iostream>
#include <concepts>
#include <vector>

// Define a simple concept
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// Using concept in template
template <Numeric T>
T add(T a, T b) {
    return a + b;
}

// Constraining a collection
template <typename T>
concept Iterable = requires(T t) {
    t.begin();
    t.end();
};

template <Iterable T>
void printCollection(const T& coll) {
    for (const auto& item : coll) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Adding numbers: " << add(5, 10) << std::endl;
    // add("A", "B"); // Compile error: Does not satisfy Numeric

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Printing collection: ";
    printCollection(v);

    return 0;
}
