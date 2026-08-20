// LeetCode 217. Contains Duplicate
// NeetCode 150 - Arrays & Hashing #1
// Given an integer array nums, return true if any value appears at least twice.

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

// Method 1: Hash set — one pass, early exit on first duplicate
// Algorithm: Insert each element into a set; if already present, return true.
// Time: O(n), Space: O(n)
bool method1_contains_duplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

// Method 2: Sort then check adjacent pairs
// Algorithm: Sort array; duplicates must be adjacent.
// Time: O(n log n), Space: O(1) if sort in-place
bool method2_sort_adjacent(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); ++i)
        if (nums[i] == nums[i - 1]) return true;
    return false;
}

int main() {
    std::vector<int> a = {1, 2, 3, 1};
    std::vector<int> b = {1, 2, 3, 4};
    std::vector<int> c = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    // method1_hash_set (active)
    std::cout << method1_contains_duplicate(a) << std::endl;  // 1 (true)
    std::cout << method1_contains_duplicate(b) << std::endl;  // 0 (false)
    std::cout << method1_contains_duplicate(c) << std::endl;  // 1 (true)

    // method2_sort_adjacent (commented out)
    // std::vector<int> a2 = a, b2 = b, c2 = c;
    // std::cout << method2_sort_adjacent(a2) << std::endl;
    // std::cout << method2_sort_adjacent(b2) << std::endl;
    // std::cout << method2_sort_adjacent(c2) << std::endl;

    return 0;
}
