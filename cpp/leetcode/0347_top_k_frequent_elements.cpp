// LeetCode 347. Top K Frequent Elements
// NeetCode 150 - Arrays & Hashing #5
// Given an integer array nums and k, return the k most frequent elements.

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>

// Method 1: Bucket sort — count freq, then buckets by frequency
// Algorithm: freq[num] = count; buckets[freq] = list of nums; scan from high freq.
// Time: O(n), Space: O(n)
std::vector<int> method1_bucket_sort(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> buckets(n + 1);
    for (auto& p : freq) buckets[p.second].push_back(p.first);
    std::vector<int> result;
    for (int f = n; f >= 1 && static_cast<int>(result.size()) < k; --f)
        for (int x : buckets[f]) {
            result.push_back(x);
            if (static_cast<int>(result.size()) == k) break;
        }
    return result;
}

// Method 2: Max-heap (priority_queue) by frequency
// Algorithm: Build freq map; push (freq, num) into max-heap; pop k times.
// Time: O(n + k log n), Space: O(n)
std::vector<int> method2_max_heap(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::less<Pair>> pq;
    for (auto& p : freq) pq.push({p.second, p.first});
    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

// Method 3: Quickselect / partial sort by frequency
// Algorithm: Get (num, freq) pairs; partial_sort or nth_element for top k by freq.
// Time: O(n) average with quickselect, Space: O(n)
std::vector<int> method3_quickselect_style(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];
    std::vector<std::pair<int, int>> pairs;
    for (auto& p : freq) pairs.push_back({p.second, p.first});
    std::nth_element(pairs.begin(), pairs.begin() + (k - 1), pairs.end(),
                     [](const auto& a, const auto& b) { return a.first > b.first; });
    std::vector<int> result;
    for (int i = 0; i < k; ++i) result.push_back(pairs[i].second);
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // method1_bucket_sort (active)
    std::vector<int> result = method1_bucket_sort(nums, k);
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";  // 1 2 (order may vary)

    // method2_max_heap (commented out)
    // result = method2_max_heap(nums, k);
    // for (int x : result) std::cout << x << " "; std::cout << "\n";

    // method3_quickselect_style (commented out)
    // result = method3_quickselect_style(nums, k);
    // for (int x : result) std::cout << x << " "; std::cout << "\n";

    return 0;
}
