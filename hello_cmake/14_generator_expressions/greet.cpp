#include <iostream>
#include "greet.h"

void greet() {
#ifdef VERBOSE_LOGGING
    std::cout << "[verbose] ";
#endif
    std::cout << "Step 14: greeting via generator-expression include paths\n";
}
