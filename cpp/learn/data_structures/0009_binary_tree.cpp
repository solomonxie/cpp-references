// Lesson: Binary Tree - Hierarchical structure with left and right children
// Compile: g++ -o 0009_binary_tree 0009_binary_tree.cpp

#include <iostream>

struct Node {
  int data;
  Node *left, *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Depth-First Search (DFS) Traversal: In-order (Left, Root, Right)
void printInOrder(Node *root) {
  if (!root)
    return;
  printInOrder(root->left);
  std::cout << root->data << " ";
  printInOrder(root->right);
}

// DFS Traversal: Pre-order (Root, Left, Right)
void printPreOrder(Node *root) {
  if (!root)
    return;
  std::cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}

int main() {
  /* Creating a simple tree:
          1
         / \
        2   3
       / \
      4   5
  */
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  std::cout << "In-order traversal: ";
  printInOrder(root);
  std::cout << "\n";

  std::cout << "Pre-order traversal: ";
  printPreOrder(root);
  std::cout << "\n";

  // Note: Manual cleanup omitted for brevity in this simple demo,
  // but essential in real applications!
  return 0;
}
