/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */

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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        vector<TreeNode*> rootLevel;
        rootLevel.push_back(root);
        while (true) {
            vector<int> level;
            vector<TreeNode*> nextLevel;
            for (TreeNode* node: rootLevel) {
                level.push_back(node->val);
                if (node->left)
                    nextLevel.push_back(node->left);
                if (node->right)
                    nextLevel.push_back(node->right);
            }
            result.push_back(level);
            rootLevel = nextLevel;
            if (nextLevel.empty()) break;
            // if (isAllNULL(nextLevel)) break;
        }
        return result;
    }
private:
    bool isAllNULL(vector<TreeNode*> arr) {
        for (TreeNode* node : arr) {
            if (node)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    vector<vector<int> > res = sol.levelOrder(root);
    for (vector<int> tmp: res) {
        for (int i: tmp) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
