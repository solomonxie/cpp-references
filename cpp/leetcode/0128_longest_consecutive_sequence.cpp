// LeetCode 128. Longest Consecutive Sequence
// NeetCode 150 - Arrays & Hashing #9
// Given an unsorted array of integers, return the length of the longest consecutive elements sequence.

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

// Method 1: Hash set — only start counting from "sequence start" (no num-1 in set)
// Algorithm: Put all in set; for each num, if num-1 not in set, extend right (num+1, num+2, ...) and update max.
// Time: O(n), Space: O(n)
int method1_set_sequence_start(std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;  // not a sequence start
        int len = 0;
        for (int v = x; s.count(v); ++v) ++len;
        best = std::max(best, len);
    }
    return best;
}

// Method 2: Sort and scan for consecutive runs
// Algorithm: Sort; traverse and count consecutive runs, track max length.
// Time: O(n log n), Space: O(1) if sort in-place
int method2_sort_scan(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::sort(nums.begin(), nums.end());
    int run = 1, best = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) {
            ++run;
            best = std::max(best, run);
        } else {
            run = 1;
        }
    }
    return best;
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};

    // method1_set_sequence_start (active)
    std::cout << method1_set_sequence_start(nums) << std::endl;  // 4 (1,2,3,4)

    // method2_sort_scan (commented out)
    // std::cout << method2_sort_scan(nums) << std::endl;

    return 0;
}
