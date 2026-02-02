// Lesson: Iterators as cursor over container, begin/end
// Compile: g++ -o 0059_iterators 0059_iterators.cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    auto it = v.begin();
    std::cout << "first: " << *it << "\n";
    ++it;
    std::cout << "second: " << *it << "\n";

    auto rit = v.rbegin();  // reverse iterator
    std::cout << "reverse: ";
    for (; rit != v.rend(); ++rit) std::cout << *rit << " ";
    std::cout << "\n";
    return 0;
}
