// Lesson: std::deque, std::list, when to use
// Compile: g++ -o 0064_deque_list 0064_deque_list.cpp

#include <iostream>
#include <deque>
#include <list>

int main() {
    std::deque<int> d = {1, 2, 3};
    d.push_front(0);
    d.push_back(4);
    std::cout << "deque (front/back O(1)): ";
    for (int x : d) std::cout << x << " ";
    std::cout << "\n";

    std::list<int> l = {10, 20, 30};
    l.push_front(0);
    l.push_back(40);
    l.insert(++l.begin(), 15);  // insert after first
    std::cout << "list (insert/erase in middle O(1)): ";
    for (int x : l) std::cout << x << " ";
    std::cout << "\n";

    // vector: dynamic array, fast random access
    // deque: double-ended queue, fast push_front/push_back
    // list: doubly linked list, fast insert/erase anywhere
    return 0;
}
