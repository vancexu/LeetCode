/*Given a binary tree, determine if it is a valid binary search tree (BST). */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // use inorder tarversal, the result should be in increasing order
    // Time O(n), Space O(1)
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        int prev = INT_MIN;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                if (prev < node->val)
                    prev = node->val;
                else 
                    return false;
                node = node->right;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(14);
    root->left->left = new TreeNode(1);
    //root->right = new TreeNode(15);
    //root->right->left = new TreeNode(6);
    if (!sol.isValidBST(root)) cout << "pass test 1";
    cout << endl;
}
