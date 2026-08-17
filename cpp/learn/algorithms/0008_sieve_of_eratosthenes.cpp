/**
 * Sieve of Eratosthenes
 * 
 * Efficient $O(n \log \log n)$ algorithm to find all primes up to 
 * a given limit $n$.
 */
#include <iostream>
#include <vector>

std::vector<int> sieve(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    std::vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
    return primes;
}

int main() {
    int n = 30;
    std::vector<int> primes = sieve(n);
    std::cout << "Primes up to " << n << ": ";
    for (int p : primes) std::cout << p << " ";
    return 0;
}
