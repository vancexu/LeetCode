/* Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;
        if (p == NULL && q == NULL) return true;
        if (p->val == q->val) 
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else 
            return false;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    if (sol.isSameTree(root, root))
        cout << "pass test 1" << endl;
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    if (!sol.isSameTree(t1,t2))
        cout << "pass test 2" << endl;

}
