/**
 * Trie (Prefix Tree)
 * 
 * Tree data structure used for efficient retrieval of keys in a 
 * large dataset of strings.
 */
#include <iostream>
#include <vector>
#include <string>

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void insert(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    bool search(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    std::cout << "Search 'apple': " << trie.search("apple") << std::endl;
    std::cout << "Search 'app': " << trie.search("app") << std::endl;
    return 0;
}
