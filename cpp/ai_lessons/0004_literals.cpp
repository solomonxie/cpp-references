// Lesson: Integer/float/char/string literals, suffixes (u, l, f)
// Compile: g++ -o 0004_literals 0004_literals.cpp

#include <iostream>

int main() {
    // Integer literals
    int dec = 42;
    int hex = 0x2A;      // 42 in hex
    int oct = 052;       // 42 in octal
    unsigned u = 42u;
    long L = 42L;
    long long LL = 42LL;

    // Float literals
    double d1 = 3.14;
    double d2 = 3.14e0;
    float f = 3.14f;
    long double ld = 3.14L;

    // Char and string literals
    char c = 'x';
    const char* s = "hello";

    std::cout << "dec=" << dec << " hex=" << hex << " oct=" << oct << "\n";
    std::cout << "float " << f << " double " << d1 << "\n";
    std::cout << "char '" << c << "' string \"" << s << "\"\n";
    return 0;
}
