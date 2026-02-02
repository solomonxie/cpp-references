// Lesson: Input/output/forward/bidirectional/random-access (brief)
// Compile: g++ -o 0065_iterators_categories 0065_iterators_categories.cpp

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {
    std::vector<int> v = {10, 20, 30};
    std::vector<int>::iterator vi = v.begin();
    // vector: random-access (+, -, [], <, etc.)
    vi += 2;
    std::cout << "vector random-access vi[2]: " << vi[0] << "\n";

    std::list<int> l = {1, 2, 3};
    std::list<int>::iterator li = l.begin();
    ++li; ++li;  // list: bidirectional (only ++, --)
    // li += 2;   // error: no += for list iterator
    std::cout << "list bidirectional *li: " << *li << "\n";

    // Categories: input, output, forward, bidirectional, random_access
    // vector -> random_access; list -> bidirectional; istream -> input
    return 0;
}
