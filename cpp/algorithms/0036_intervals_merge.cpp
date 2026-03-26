/**
 * Intervals - Merge Intervals
 * 
 * Given an array of intervals, merge all overlapping intervals.
 * O(n*logn) due to sorting.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return {};
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

int main() {
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = mergeIntervals(intervals);
    std::cout << "Merged intervals: ";
    for (auto& interval : res) std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    return 0;
}
