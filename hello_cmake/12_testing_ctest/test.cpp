#include <cassert>
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
    assert(add(2, 3) == 5);   // Step 12: a hand-rolled assert-based test, no framework needed
    std::cout << "Step 12: hello_test passed\n";
    return 0;
}
