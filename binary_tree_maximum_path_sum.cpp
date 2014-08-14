/* Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree. */

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
       int maximum = (root == NULL) ? 0 : root->val;
       maxPathSum(root, maximum);
       return maximum;
    }

private:
    // compute the max path and record the maximum path so far. 
    int maxPathSum(TreeNode* root, int& maximum) {
        if (root == NULL) return 0;
        int left_max = max(maxPathSum(root->left, maximum), 0);
        int right_max = max(maxPathSum(root->right, maximum), 0);
        maximum = max(left_max + root->val + right_max, maximum);
        return max(left_max, right_max) + root->val;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout << sol.maxPathSum(root);
    cout << endl;
}
