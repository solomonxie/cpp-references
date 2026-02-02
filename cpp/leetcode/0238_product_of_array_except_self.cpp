// LeetCode 238. Product of Array Except Self
// NeetCode 150 - Arrays & Hashing #6
// Return an array answer such that answer[i] = product of all elements except nums[i]. No division.

#include <vector>
#include <iostream>

// Method 1: Prefix and suffix products (two passes)
// Algorithm: answer[i] = prefix[i-1] * suffix[i+1]; build prefix in one pass, suffix in another.
// Time: O(n), Space: O(n) for prefix/suffix arrays
std::vector<int> method1_prefix_suffix_arrays(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> prefix(n, 1), suffix(n, 1);
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] * nums[i - 1];
    for (int i = n - 2; i >= 0; --i) suffix[i] = suffix[i + 1] * nums[i + 1];
    std::vector<int> answer(n);
    for (int i = 0; i < n; ++i) answer[i] = prefix[i] * suffix[i];
    return answer;
}

// Method 2: O(1) extra space — use answer as prefix, then multiply by suffix in place
// Algorithm: First pass: answer[i] = product of nums[0..i-1]. Second pass: multiply by product of nums[i+1..n-1].
// Time: O(n), Space: O(1) (output not counted)
std::vector<int> method2_prefix_then_suffix_inplace(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> answer(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
    return answer;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};

    // method1_prefix_suffix_arrays (active)
    std::vector<int> result = method1_prefix_suffix_arrays(nums);
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";  // 24 12 8 6

    // method2_prefix_then_suffix_inplace (commented out)
    // result = method2_prefix_then_suffix_inplace(nums);
    // for (int x : result) std::cout << x << " "; std::cout << "\n";

    return 0;
}
