// LeetCode 1. Two Sum
// NeetCode 150 - Arrays & Hashing #3
// Given an array of integers nums and target, return indices of the two numbers that add up to target.

#include <vector>
#include <unordered_map>
#include <iostream>

// Method 1: Hash map — one pass
// Algorithm: For each num, check if (target - num) exists in map; store num -> index.
// Time: O(n), Space: O(n)
std::vector<int> method1_hash_map_onepass(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> val_to_idx;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        if (val_to_idx.count(need))
            return {val_to_idx[need], i};
        val_to_idx[nums[i]] = i;
    }
    return {};
}

// Method 2: Hash map — two pass
// Algorithm: First pass build map (value -> index); second pass look for complement.
// Time: O(n), Space: O(n)
std::vector<int> method2_hash_map_twopass(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> val_to_idx;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        val_to_idx[nums[i]] = i;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        if (val_to_idx.count(need) && val_to_idx[need] != i)
            return {i, val_to_idx[need]};
    }
    return {};
}

// Method 3: Brute force — two loops
// Algorithm: For each pair (i, j), check if nums[i] + nums[j] == target.
// Time: O(n^2), Space: O(1)
std::vector<int> method3_brute_force(std::vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i)
        for (size_t j = i + 1; j < nums.size(); ++j)
            if (nums[i] + nums[j] == target)
                return {static_cast<int>(i), static_cast<int>(j)};
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // method1_hash_map_onepass (active)
    std::vector<int> result = method1_hash_map_onepass(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;  // 0 1

    // method2_hash_map_twopass (commented out)
    // result = method2_hash_map_twopass(nums, target);
    // std::cout << result[0] << " " << result[1] << std::endl;

    // method3_brute_force (commented out)
    // result = method3_brute_force(nums, target);
    // std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}
