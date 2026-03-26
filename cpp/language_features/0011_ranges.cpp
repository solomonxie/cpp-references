/**
 * 0011_ranges.cpp
 * 
 * Demonstrates C++20 Ranges library, providing composable 
 * views and algorithms that work directly on containers.
 */
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use pipe operator to compose views
    auto results = numbers | std::views::filter([](int n) { return n % 2 == 0; })
                           | std::views::transform([](int n) { return n * n; });

    std::cout << "Even numbers squared: ";
    for (int v : results) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Sorting a range directly
    std::vector<int> v2 = {5, 2, 8, 1, 9};
    std::ranges::sort(v2);
    
    std::cout << "Sorted range: ";
    for (int n : v2) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
