// Lesson: C-string char[], \0, strlen, strcpy
// Compile: g++ -o 0035_cstring 0035_cstring.cpp

#include <iostream>
#include <cstring>

int main() {
    char s1[] = "hello";  // includes '\0', size 6
    std::cout << "s1 = \"" << s1 << "\" strlen = " << std::strlen(s1) << "\n";

    char s2[10];
    std::strcpy(s2, "hi");  // copy "hi\0" into s2
    std::cout << "strcpy(s2, \"hi\") -> s2 = \"" << s2 << "\"\n";

    std::strcat(s2, "!");   // append
    std::cout << "strcat(s2, \"!\") -> s2 = \"" << s2 << "\"\n";

    std::cout << "strcmp(\"abc\", \"abd\") = " << std::strcmp("abc", "abd") << "\n";
    return 0;
}
