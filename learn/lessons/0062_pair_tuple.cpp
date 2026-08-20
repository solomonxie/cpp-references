// Lesson: std::pair, std::tuple, get
// Compile: g++ -o 0062_pair_tuple 0062_pair_tuple.cpp -std=c++11

#include <iostream>
#include <string>
#include <utility>
#include <tuple>

int main() {
    std::pair<int, std::string> p = {42, "hello"};
    std::cout << "pair: " << p.first << " " << p.second << "\n";

    auto p2 = std::make_pair(1, 3.14);
    std::cout << "make_pair: " << p2.first << " " << p2.second << "\n";

    std::tuple<int, double, std::string> t(1, 2.5, "hi");
    std::cout << "tuple: " << std::get<0>(t) << " " << std::get<1>(t)
              << " " << std::get<2>(t) << "\n";

    auto t2 = std::make_tuple(10, 20, 30);
    std::cout << "make_tuple: " << std::get<0>(t2) << " " << std::get<1>(t2) << "\n";
    return 0;
}
