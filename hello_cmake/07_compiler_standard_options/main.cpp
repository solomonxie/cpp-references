#include <iostream>
#include <tuple>

int main() {
    auto [a, b] = std::make_pair(1, 2);  // Step 7: structured bindings need C++17
    std::cout << "Step 7: " << a << " + " << b << " = " << a + b << "\n";
    return 0;
}
