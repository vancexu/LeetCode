/* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.*/

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
    vector<TreeNode*> NULLvec = {NULL};

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

private:
    // return a list of BST of [low,high]
    vector<TreeNode*> generateTrees(int low, int high) {
        if (low > high) return NULLvec;
        vector<TreeNode*> roots;
        for (int i=low; i<=high; ++i) {
            vector<TreeNode*> left_subtrees = generateTrees(low, i-1);
            vector<TreeNode*> right_subtrees = generateTrees(i+1, high);
            for (TreeNode* left: left_subtrees) {
                for (TreeNode* right: right_subtrees) {
                    roots.push_back(new TreeNode(i));
                    roots.back()->left = left;
                    roots.back()->right = right;
                }
            }
        }
        return roots;
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
    vector<TreeNode*> vec = sol.generateTrees(3);
    if (vec.size() == 5) cout << "pass test 1";
    cout << endl;
}
