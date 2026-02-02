// Lesson: std::array<T,N>, .size(), bounds
// Compile: g++ -o 0033_std_array 0033_std_array.cpp -std=c++11

#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    std::array<int, 3> arr2 = {1, 2, 3};

    std::cout << "arr[0] = " << arr[0] << ", arr.at(2) = " << arr.at(2) << "\n";
    std::cout << "arr.size() = " << arr.size() << "\n";

    // .at() does bounds checking (throws if out of range)
    // arr.at(10);  // would throw std::out_of_range

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
