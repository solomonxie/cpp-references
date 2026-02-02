// LeetCode 49. Group Anagrams
// NeetCode 150 - Arrays & Hashing #4
// Given an array of strings, group the anagrams together.

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <iostream>

// Method 1: Sort each string as key
// Algorithm: Use sorted string as key in map; anagrams share the same key.
// Time: O(n * k log k) where k = max string length, Space: O(n * k)
std::vector<std::vector<std::string>> method1_sort_as_key(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (std::string& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& p : groups) result.push_back(std::move(p.second));
    return result;
}

// Method 2: Frequency string as key (e.g. "a2b1c1" for "aabc")
// Algorithm: Build key from character counts; anagrams have same counts.
// Time: O(n * k), Space: O(n * k)
std::vector<std::vector<std::string>> method2_freq_string_key(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (std::string& s : strs) {
        std::array<int, 26> count{};
        for (char c : s) ++count[c - 'a'];
        std::string key;
        for (int i = 0; i < 26; ++i)
            if (count[i]) key += static_cast<char>('a' + i) + std::to_string(count[i]);
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& p : groups) result.push_back(std::move(p.second));
    return result;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // method1_sort_as_key (active)
    auto result = method1_sort_as_key(strs);
    for (auto& group : result) {
        for (auto& s : group) std::cout << s << " ";
        std::cout << "\n";
    }
    // e.g. bat | eat tea ate | tan nat

    // method2_freq_string_key (commented out)
    // result = method2_freq_string_key(strs);
    // for (auto& group : result) { for (auto& s : group) std::cout << s << " "; std::cout << "\n"; }

    return 0;
}
