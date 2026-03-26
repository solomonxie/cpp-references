/**
 * 0002_mutex_atomic.cpp
 * 
 * Demonstrates thread safety techniques:
 * 1. std::mutex and std::lock_guard for critical sections.
 * 2. std::atomic for lock-free primitive operations.
 */
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

// Shared resource with Mutex protection
int counter_mutex = 0;
std::mutex mtx;

// Shared resource with Atomic protection
std::atomic<int> counter_atomic(0);

void incrementMutex() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        counter_mutex++;
    }
}

void incrementAtomic() {
    for (int i = 0; i < 10000; ++i) {
        counter_atomic++; // Atomic increment
    }
}

int main() {
    std::vector<std::thread> threads;

    // Test Mutex protection
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementMutex);
    }
    for (auto& t : threads) t.join();
    threads.clear();

    // Test Atomic protection
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementAtomic);
    }
    for (auto& t : threads) t.join();

    std::cout << "Final counter (Mutex): " << counter_mutex << " (Expected 100000)" << std::endl;
    std::cout << "Final counter (Atomic): " << counter_atomic << " (Expected 100000)" << std::endl;

    return 0;
}
