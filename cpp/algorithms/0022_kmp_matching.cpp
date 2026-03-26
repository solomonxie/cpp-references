/**
 * KMP Algorithm (Knuth-Morris-Pratt)
 * 
 * $O(n + m)$ string matching algorithm that uses a "prefix function" 
 * to avoid redundant comparisons.
 */
#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& pat) {
    int m = pat.length();
    std::vector<int> lps(m);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

void KMPSearch(const std::string& pat, const std::string& txt) {
    int m = pat.length();
    int n = txt.length();
    std::vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) { i++; j++; }
        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    std::string txt = "ABABDABACDABABCABAB";
    std::string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
