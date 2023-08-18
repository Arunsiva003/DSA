#include <iostream>

// Define a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Recursive function to perform preorder traversal and print nth node
int preorderNthNode(TreeNode* node, int& n) {
    if (node == nullptr) {
        return 0; // Return 0 for null nodes
    }

    // If the current node is the nth node, print its value
    if (--n == 0) {
        std::cout << "The " << n + 1 << "th node in preorder is: " << node->val << std::endl;
    }

    // Recurse on the left subtree
    preorderNthNode(node->left, n);

    // Recurse on the right subtree
    preorderNthNode(node->right, n);
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int n = 3; // Change this to the desired n value
    preorderNthNode(root, n);

    // Clean up memory (not shown in this example)
    
    return 0;
}
