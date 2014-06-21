/* Given a binary tree, return the postorder traversal of its nodes' values. */

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;

        stack<TreeNode*> s;
        s.push(root);
        TreeNode* prev = NULL;
        while (!s.empty()) {
            TreeNode* node = s.top();

            if (!prev || prev->left == node || prev->right == node) {
                if (node->left) {
                    s.push(node->left);
                } else if (node->right) {
                    s.push(node->right);
                } else {
                    result.push_back(node->val);
                    s.pop();
                }
            } else if (node->left == prev) {
                if (node->right) {
                    s.push(node->right);
                } else {
                    result.push_back(node->val);
                    s.pop();
                }
            } else if (node->right == prev) {
                result.push_back(node->val);
                s.pop();
            }

            prev = node;
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
    for (int tmp: sol.postorderTraversal(root))
        cout << tmp << " " ;
    cout << endl;
}
