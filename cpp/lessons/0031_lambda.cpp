// Lesson: Lambda syntax [](){}, capture [=]/[&]
// Compile: g++ -o 0031_lambda 0031_lambda.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // [](){}  capture, params, body
    auto add = [](int a, int b) { return a + b; };
    std::cout << "add(3, 4) = " << add(3, 4) << "\n";

    int x = 10;
    auto capture_by_value = [x]() { return x; };   // copy of x
    auto capture_by_ref = [&x]() { return x; };   // reference to x
    std::cout << "capture_by_value() = " << capture_by_value() << "\n";
    x = 20;
    std::cout << "after x=20: capture_by_value() = " << capture_by_value()
              << ", capture_by_ref() = " << capture_by_ref() << "\n";

    std::vector<int> v = {3, 1, 4, 1, 5};
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    std::cout << "sorted descending: ";
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
