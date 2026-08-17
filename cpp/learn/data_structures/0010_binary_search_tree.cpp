// Lesson: Binary Search Tree (BST) - Ordered binary tree
// Compile: g++ -o 0010_binary_search_tree 0010_binary_search_tree.cpp

#include <iostream>

struct Node {
  int data;
  Node *left, *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int val) {
  if (!root)
    return new Node(val);

  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

bool search(Node *root, int val) {
  if (!root)
    return false;
  if (root->data == val)
    return true;

  if (val < root->data)
    return search(root->left, val);
  else
    return search(root->right, val);
}

void printInOrder(Node *root) {
  if (!root)
    return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
}

int main() {
  Node *root = nullptr;
  int values[] = {50, 30, 20, 40, 70, 60, 80};

  std::cout << "Inserting values into BST...\n";
  for (int v : values) {
    root = insert(root, v);
  }

  std::cout << "In-order (should be sorted): ";
  printInOrder(root);
  std::cout << "\n";

  int target = 40;
  std::cout << "Searching for " << target << ": "
            << (search(root, target) ? "Found" : "Not Found") << "\n";

  return 0;
}
