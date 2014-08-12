/* Given a binary tree, return the inorder traversal of its nodes' values. */

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;

        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }

};

void printResult(vector<int> res) {
    for (int i: res)
        cout << i << " ";
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = sol.inorderTraversal(root);
    printResult(res);
    cout << endl;
}
