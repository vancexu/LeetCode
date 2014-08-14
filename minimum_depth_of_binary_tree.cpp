/* Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. */

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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 1;
        vector<TreeNode*> level;
        level.push_back(root);
        while (true) {
            vector<TreeNode*> nextLevel;
            for (TreeNode* node: level) {
                if (node->left)
                    nextLevel.push_back(node->left);
                if (node->right)
                    nextLevel.push_back(node->right);
                if (node->left == NULL && node->right == NULL)
                    return depth;
            }
            level = nextLevel;
            depth++;
        }
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout << sol.minDepth(root);
    cout << endl;
}
