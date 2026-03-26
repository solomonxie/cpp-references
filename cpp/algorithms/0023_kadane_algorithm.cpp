/**
 * Kadane's Algorithm
 * 
 * $O(n)$ algorithm to find the maximum sum contiguous subarray.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    int max_so_far = nums[0];
    int current_max = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        current_max = std::max(nums[i], current_max + nums[i]);
        max_so_far = std::max(max_so_far, current_max);
    }
    return max_so_far;
}

int main() {
    std::vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Max subarray sum: " << maxSubArray(data) << " (expected 6)" << std::endl;
    return 0;
}
