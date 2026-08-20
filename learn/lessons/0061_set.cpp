// Lesson: std::set, uniqueness, ordering
// Compile: g++ -o 0061_set 0061_set.cpp

#include <iostream>
#include <set>

int main() {
    std::set<int> s = {30, 10, 20, 10, 20};  // duplicates removed, sorted
    std::cout << "set size: " << s.size() << "\n";  // 3

    s.insert(15);
    s.insert(10);  // no effect, already present
    std::cout << "elements: ";
    for (int x : s) std::cout << x << " ";
    std::cout << "\n";

    if (s.find(20) != s.end()) std::cout << "20 is in set\n";
    if (s.count(25) == 0) std::cout << "25 is not in set\n";
    return 0;
}
