/* Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. */

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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        bool result = true;
        isBalancedAux(root, result);
        return result;
    }

private:
    // isBalancedAux return the height of tree 
    // and check balanced or not at the same time
    int isBalancedAux(TreeNode* root, bool& is_balanced) {
        if (root == NULL) return 0;
        int left_height = isBalancedAux(root->left, is_balanced);
        int right_height = isBalancedAux(root->right, is_balanced);
        if (is_balanced)
            is_balanced = abs(left_height - right_height) <= 1;
        return max(left_height, right_height) + 1;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    if (!sol.isBalanced(root)) cout << "pass test 1";
    cout << endl;
}
