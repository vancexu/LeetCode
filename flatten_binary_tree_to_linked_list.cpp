/* Given a binary tree, flatten it to a linked list in-place. */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* it = root;
        while (it->right != NULL)
            it = it->right;
        it->right = tmp;
        flatten(tmp);
    }
};

void printBinaryTree(TreeNode* root) {
    if (root) {
        printBinaryTree(root->left);
        printBinaryTree(root->right);
        cout << root->val << " ";
    }
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    printBinaryTree(root);
    cout << endl;
    sol.flatten(root);
    printBinaryTree(root);
    cout << endl;
}
