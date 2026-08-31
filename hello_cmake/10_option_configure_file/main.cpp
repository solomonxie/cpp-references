#include <iostream>
#include "config.h"

int main() {
    std::cout << "Step 10: hello v" << APP_VERSION << "\n";
#ifdef ENABLE_GREETING
    std::cout << "Step 10: greeting is enabled\n";
#endif
    return 0;
}
