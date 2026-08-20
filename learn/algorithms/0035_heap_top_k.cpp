/**
 * Heap Pattern - Top K Frequent Elements
 * 
 * Demonstrates the use of a priority_queue to find the k most 
 * frequent elements in O(n*logk) time.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> counts;
    for (int num : nums) counts[num]++;

    typedef std::pair<int, int> pii;
    // Min-heap to keep track of top k
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    for (auto const& [val, freq] : counts) {
        pq.push({freq, val});
        if (pq.size() > k) pq.pop();
    }

    std::vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> res = topKFrequent(nums, k);
    std::cout << "Top " << k << " frequent elements: ";
    for (int x : res) std::cout << x << " ";
    return 0;
}
