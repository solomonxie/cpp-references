/**
 * Bit Manipulation Basics
 * 
 * Common bitwise operations: check bit, set bit, clear bit, 
 * toggle bit, and count set bits.
 */
#include <iostream>

bool getBit(int n, int i) { return (n & (1 << i)) != 0; }
int setBit(int n, int i) { return n | (1 << i); }
int clearBit(int n, int i) { return n & ~(1 << i); }
int toggleBit(int n, int i) { return n ^ (1 << i); }

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clears the lowest set bit
        count++;
    }
    return count;
}

int main() {
    int n = 5; // 0101
    std::cout << "Number: " << n << " (binary 0101)" << std::endl;
    std::cout << "Bit at index 0: " << getBit(n, 0) << std::endl;
    std::cout << "Set bit at index 1: " << setBit(n, 1) << " (0111 = 7)" << std::endl;
    std::cout << "Count set bits: " << countSetBits(n) << std::endl;
    return 0;
}
