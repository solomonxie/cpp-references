#include <iostream>

int main() {
#ifdef DEBUG_BUILD
    std::cout << "Step 8: this is a Debug build\n";
#else
    std::cout << "Step 8: this is a Release (or other) build\n";
#endif
    return 0;
}
