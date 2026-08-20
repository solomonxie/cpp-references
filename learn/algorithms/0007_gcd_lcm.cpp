/**
 * GCD & LCM (Euclidean Algorithm)
 * 
 * GCD: Greatest Common Divisor using the Euclidean algorithm $O(\log(\min(a,b)))$.
 * LCM: Least Common Multiple using the relationship: $LCM(a, b) = |a*b| / GCD(a, b)$.
 */
#include <iostream>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b; // Divide first to avoid overflow
}

int main() {
    long long a = 12, b = 18;
    std::cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
    std::cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << std::endl;
    return 0;
}
