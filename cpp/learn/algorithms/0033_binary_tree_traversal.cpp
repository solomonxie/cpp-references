/**
 * Binary Tree Traversal
 * 
 * Recursive implementations of Inorder, Preorder, and Postorder traversals.
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    std::cout << "Inorder: "; inorder(root); std::cout << std::endl;
    std::cout << "Preorder: "; preorder(root); std::cout << std::endl;
    std::cout << "Postorder: "; postorder(root); std::cout << std::endl;
    return 0;
}
