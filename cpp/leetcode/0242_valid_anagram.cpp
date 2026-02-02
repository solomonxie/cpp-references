// LeetCode 242. Valid Anagram
// NeetCode 150 - Arrays & Hashing #2
// Given two strings s and t, return true if t is an anagram of s.

#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <iostream>

// Method 1: Sort both strings and compare
// Algorithm: Anagrams have same characters; sorting normalizes them.
// Time: O(n log n), Space: O(1) in C++ (in-place sort; depends on impl)
bool method1_sort_compare(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}

// Method 2: Frequency count with hash map
// Algorithm: Count each character in s, decrement with t; all counts must be 0.
// Time: O(n), Space: O(1) — at most 26 keys for lowercase letters
bool method2_freq_hashmap(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, int> freq;
    for (char c : s) ++freq[c];
    for (char c : t) {
        if (--freq[c] < 0) return false;
    }
    return true;
}

// Method 3: Fixed-size array (when input is lowercase a–z only)
// Algorithm: Same as method 2 but use array[26] for counts.
// Time: O(n), Space: O(1)
bool method3_freq_array(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::array<int, 26> count{};
    for (char c : s) ++count[c - 'a'];
    for (char c : t) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    std::string s1 = "anagram", t1 = "nagaram";
    std::string s2 = "rat", t2 = "car";

    // method1_sort_compare (active)
    std::cout << method1_sort_compare(s1, t1) << std::endl;  // 1 (true)
    std::cout << method1_sort_compare(s2, t2) << std::endl;  // 0 (false)

    // method2_freq_hashmap (commented out)
    // std::cout << method2_freq_hashmap(s1, t1) << std::endl;
    // std::cout << method2_freq_hashmap(s2, t2) << std::endl;

    // method3_freq_array (commented out)
    // std::cout << method3_freq_array(s1, t1) << std::endl;
    // std::cout << method3_freq_array(s2, t2) << std::endl;

    return 0;
}
