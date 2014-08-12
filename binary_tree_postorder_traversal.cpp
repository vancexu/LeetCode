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
        TreeNode* node = root;
        TreeNode* prev = root;
        while (!s.empty() || node) {
            if (node) {
                if (node->left == prev) {
                    prev = node;
                    node = node->right;
                } else if (node->right == prev) {
                    s.pop();
                    result.push_back(node->val);
                    prev = node;
                    if (!s.empty()) node = s.top();
                    else node = NULL;
                } else {
                    s.push(node);
                    prev = node;
                    node = node->left;
                }
            } else if (node == prev->right) { // the order is so important here. IF check node == prev->left first, it would be dead loop.
                node = s.top();
                s.pop();
                result.push_back(node->val);
                prev = node;
                if (!s.empty()) node = s.top();
                else node = NULL;
            } else if (node == prev->left) {
                node = s.top();
                prev = node;
                node = node->right;
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
    for (int tmp: sol.postorderTraversal(root))
        cout << tmp << " " ;
    cout << endl;
}
