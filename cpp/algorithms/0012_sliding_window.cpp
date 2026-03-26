/**
 * Sliding Window Pattern
 * 
 * Used for array/string problems where you need to find a subarray/substring 
 * that satisfies certain conditions.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxSumSubarray(const std::vector<int>& arr, int k) {
    int maxSum = 0, currentSum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];
        if (i >= k - 1) {
            maxSum = std::max(maxSum, currentSum);
            currentSum -= arr[i - (k - 1)];
        }
    }
    return maxSum;
}

int main() {
    std::vector<int> data = {2, 1, 5, 1, 3, 2};
    int k = 3;
    std::cout << "Max sum of subarray of size " << k << ": " << maxSumSubarray(data, k) << std::endl;
    return 0;
}
