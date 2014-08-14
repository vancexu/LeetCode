/* Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        vector<TreeNode*> level;
        level.push_back(root);
        while (true) {
            vector<TreeNode*> nextLevel;
            for (TreeNode* node: level) {
                if (node->left) 
                    nextLevel.push_back(node->left);
                if (node->right)
                    nextLevel.push_back(node->right);
            }
            level = nextLevel;
            depth++;
            if (nextLevel.empty())
                return depth;
        }   
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout << sol.maxDepth(root);
    cout << endl;
}
