/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. */

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) 
            return (sum == 0) ? true: false;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
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
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout << (true == sol.hasPathSum(root, 5)) << endl;
    cout << (true == sol.hasPathSum(root, 7)) << endl;
    cout << (false == sol.hasPathSum(root, 0)) << endl;
    cout << endl;
}
