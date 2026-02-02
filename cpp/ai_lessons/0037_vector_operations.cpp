// Lesson: insert, erase, clear, iteration
// Compile: g++ -o 0037_vector_operations 0037_vector_operations.cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};
    v.insert(v.begin() + 1, 15);  // insert 15 at index 1
    std::cout << "after insert: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    v.erase(v.begin() + 2);  // remove element at index 2
    std::cout << "after erase: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "v.empty() = " << v.empty() << "\n";
    v.clear();
    std::cout << "after clear: v.size() = " << v.size() << " v.empty() = " << v.empty() << "\n";
    return 0;
}
