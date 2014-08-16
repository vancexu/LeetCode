/* Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure. */

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
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        bool first_time = false;
        TreeNode* first_node;
        TreeNode* second_node;
        TreeNode* last_node;
        int prev = INT_MIN;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                if (prev > node->val) {
                    if (!first_time) {
                        first_time = true;
                        first_node = last_node;
                        second_node = node;
                    } else {
                        second_node = node;
                        break;
                    }
                }
                prev = node->val;
                last_node = node;
                node = node->right;
            }
        }
        int tmp = first_node->val;
        first_node->val = second_node->val;
        second_node->val = tmp;
    }
};

void printBinaryTree(TreeNode* root) {
    if (root) {
        printBinaryTree(root->left);
        cout << root->val << " ";
        printBinaryTree(root->right);
    }
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    sol.recoverTree(root);
    printBinaryTree(root);
    cout << endl;
}
