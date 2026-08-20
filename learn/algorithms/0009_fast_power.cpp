/**
 * Fast Power (Binary Exponentiation)
 * 
 * Computes $a^b \pmod m$ in $O(\log b)$ time.
 */
#include <iostream>

long long fastPower(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    std::cout << "2^10 % 1000 = " << fastPower(2, 10, 1000) << std::endl;
    return 0;
}
