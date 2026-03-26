/**
 * 0013_exception_safety.cpp
 * 
 * Demonstrates exception safety levels:
 * 1. Basic: No leaks, object valid.
 * 2. Strong: Commit-or-rollback (no side effects on fail).
 * 3. Nothrow: Guarantee no exceptions.
 */
#include <iostream>
#include <vector>
#include <string>

class Database {
    std::vector<int> data;
public:
    // Strong Exception Safety (using copy-and-swap idiom)
    void addData(const std::vector<int>& newData) {
        std::vector<int> temp = data; // Copy current state
        for (int val : newData) {
            if (val < 0) throw std::runtime_error("Negative data not allowed!");
            temp.push_back(val);
        }
        std::swap(data, temp); // Swap on success (no-throw swap)
    }

    void print() {
        for (int i : data) std::cout << i << " ";
        std::cout << std::endl;
    }
};

int main() {
    Database db;
    std::vector<int> goodData = {1, 2, 3};
    std::vector<int> badData = {4, -1, 5};

    try {
        db.addData(goodData);
        std::cout << "Good data added." << std::endl;
        db.addData(badData); // This will fail
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "Current DB state (remains unchanged after fail): ";
    db.print();

    return 0;
}
