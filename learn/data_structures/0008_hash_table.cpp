// Lesson: Hash Table - Key-Value pairs with fast lookup
// Compile: g++ -o 0008_hash_table 0008_hash_table.cpp

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  // std::unordered_map uses a hash table internally
  std::unordered_map<std::string, int> scores;

  // 1. Insertion
  scores["Alice"] = 95;
  scores["Bob"] = 88;
  scores.insert({"Charlie", 92});

  // 2. Lookup (Average O(1))
  std::string name = "Alice";
  if (scores.find(name) != scores.end()) {
    std::cout << name << "'s score: " << scores[name] << "\n";
  }

  // 3. Iteration
  std::cout << "\nAll scores:\n";
  for (const auto &pair : scores) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }

  // 4. Removal
  scores.erase("Bob");
  std::cout << "\nAfter removing Bob, size: " << scores.size() << "\n";

  return 0;
}
