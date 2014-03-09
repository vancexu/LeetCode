/* Given a binary tree, return the preorder traversal of its nodes' values. */

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;

        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        while (!s.empty()) {
            node = s.top();
            s.pop();
            if (node) {
                result.push_back(node->val);
                s.push(node->right);
                s.push(node->left);
            }
        }
        return result;
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
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    // printBinaryTree(root);
    // cout << endl;
    vector<int> test = sol.preorderTraversal(root);
    for (int i : test)
        cout << i << " ";
    cout << endl;
}
