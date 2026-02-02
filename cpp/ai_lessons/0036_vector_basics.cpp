// Lesson: std::vector, push_back, size, indexing
// Compile: g++ -o 0036_vector_basics 0036_vector_basics.cpp

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "v.size() = " << v.size() << "\n";
    std::cout << "v[0] = " << v[0] << " v[1] = " << v[1] << "\n";

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    std::cout << "v2: ";
    for (size_t i = 0; i < v2.size(); ++i) std::cout << v2[i] << " ";
    std::cout << "\n";

    std::vector<double> v3(5, 3.14);  // 5 elements, each 3.14
    std::cout << "v3.size() = " << v3.size() << " v3[0] = " << v3[0] << "\n";
    return 0;
}
