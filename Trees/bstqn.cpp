#include <iostream>
#include <set>

// Define a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Insert a new value into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search for a value in the BST and print its left and right nodes
void searchAndPrint(TreeNode* root, int value) {
    if (root == nullptr) {
        return;
    }

    if (root->val == value) {
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        if (leftNode) {
            std::cout << "Left Node: " << leftNode->val << std::endl;
        } else {
            std::cout << "Left Node: No left node." << std::endl;
        }

        if (rightNode) {
            std::cout << "Right Node: " << rightNode->val << std::endl;
        } else {
            std::cout << "Right Node: No right node." << std::endl;
        }

        return;
    }

    if (value < root->val) {
        searchAndPrint(root->left, value);
    } else {
        searchAndPrint(root->right, value);
    }
}

int main() {
    TreeNode* root = nullptr;
    int searchValue = 0;
    int input;

    std::cout << "Enter input numbers. Repeat to stop and set the repeated input as the search element." << std::endl;

    std::set<int> inputSet;

    while (true) {
        std::cin >> input;

        if (inputSet.find(input) != inputSet.end()) {
            searchValue = input;
            break; // Stop iteration on repeated input
        }
        inputSet.insert(input);
        root = insert(root, input);
    }

    std::cout << "Search Element: " << searchValue << std::endl;
    searchAndPrint(root, searchValue);

    // Clean up memory (not shown in this example)

    return 0;
}
