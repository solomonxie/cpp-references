/**
 * 0008_sfinae.cpp
 * 
 * Demonstrates SFINAE (Substitution Failure Is Not An Error)
 * using std::enable_if to enable/disable template overloads based 
 * on type properties.
 */
#include <iostream>
#include <type_traits>

// Enable only for integral types
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
checkType(T val) {
    std::cout << val << " is an integral type." << std::endl;
}

// Enable only for floating point types
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
checkType(T val) {
    std::cout << val << " is a floating point type." << std::endl;
}

int main() {
    checkType(10);     // Integral
    checkType(10.5);   // Floating point
    // checkType("Hi"); // Compile error: No matching overload

    return 0;
}
