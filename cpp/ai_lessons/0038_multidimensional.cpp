// Lesson: 2D array / vector<vector<T>>
// Compile: g++ -o 0038_multidimensional 0038_multidimensional.cpp

#include <iostream>
#include <vector>
#include <array>

int main() {
    // C-style 2D array
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    std::cout << "arr[1][2] = " << arr[1][2] << "\n";

    // std::array of std::array
    std::array<std::array<int, 3>, 2> a = {{{1, 2, 3}, {4, 5, 6}}};
    std::cout << "a[1][2] = " << a[1][2] << "\n";

    // vector of vectors (dynamic)
    std::vector<std::vector<int>> v = {{1, 2}, {3, 4, 5}, {6}};
    std::cout << "v[1][2] = " << v[1][2] << "\n";
    v[0].push_back(10);
    std::cout << "v[0].size() after push_back = " << v[0].size() << "\n";
    return 0;
}
