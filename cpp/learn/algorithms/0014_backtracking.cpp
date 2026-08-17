/**
 * Backtracking Pattern
 * 
 * Systematic search for a solution among all possible candidates. 
 * Often used for permutations, subsets, and puzzle solving (N-Queens).
 */
#include <iostream>
#include <vector>
#include <string>

void findSubsets(const std::string& s, int index, std::string current) {
    if (index == s.length()) {
        std::cout << "\"" << current << "\" ";
        return;
    }
    // Include the character
    findSubsets(s, index + 1, current + s[index]);
    // Exclude the character
    findSubsets(s, index + 1, current);
}

int main() {
    std::string s = "abc";
    std::cout << "Subsets of " << s << ": ";
    findSubsets(s, 0, "");
    return 0;
}
