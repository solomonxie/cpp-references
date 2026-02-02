// Lesson: std::sort, find, for_each from <algorithm>
// Compile: g++ -o 0063_algorithms 0063_algorithms.cpp

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};
    std::sort(v.begin(), v.end());
    std::cout << "sorted: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) std::cout << "found 8 at index " << (it - v.begin()) << "\n";

    std::cout << "for_each: ";
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << "\n";

    int count = std::count(v.begin(), v.end(), 1);
    std::cout << "count(1) = " << count << "\n";
    return 0;
}
