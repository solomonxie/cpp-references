// Lesson: cerr, endl vs '\n', buffering
// Compile: g++ -o 0016_cerr_endl 0016_cerr_endl.cpp

#include <iostream>

int main() {
    std::cout << "cout: normal output (buffered)\n";
    std::cerr << "cerr: error/diagnostic output (often unbuffered)\n";

    std::cout << "Using endl flushes the buffer immediately.";
    std::cout << std::endl;

    std::cout << "Using \\n does not necessarily flush (buffer may hold until full or program end).\n";

    // For logging/debugging, cerr appears immediately; cout may be delayed.
    std::cerr << "Debug: step 1\n";
    std::cout << "Step 2 (cout)\n";
    std::cerr << "Debug: step 3\n";
    return 0;
}
