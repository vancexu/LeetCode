/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isSameTree(root->left, reverseTree(root->right));
    }
private:
    TreeNode* reverseTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* tmp = reverseTree(root->left);
        root->left = reverseTree(root->right);
        root->right = tmp;
        return root;
    }
    
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
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    if (sol.isSymmetric(root)) cout << "pass test 1" << endl;
    TreeNode* tree2 = new TreeNode(1);
    if (sol.isSymmetric(tree2)) cout << "pass test 2";
    cout << endl;
    //TreeNode* t = sol.reverseTree(root->right);
    //printBinaryTree(t);
}
