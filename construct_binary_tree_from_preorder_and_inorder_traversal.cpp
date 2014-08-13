/* Given preorder and inorder traversal of a tree, construct the binary tree. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> hashmap_inorder;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* result;
        for (int i=0; i<inorder.size(); ++i)
            this->hashmap_inorder[inorder[i]] = i;
        result = buildTree(preorder, inorder, 0, 0, inorder.size());
        return result;
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int in_end) {
        TreeNode* result;
        if (in_end - in_start >= 1) {
            result = new TreeNode(preorder[pre_start]);
            int root_index = hashmap_inorder[preorder[pre_start]];
            result->left = buildTree(preorder, inorder, pre_start+1, in_start, root_index);
            result->right = buildTree(preorder, inorder, pre_start+root_index-in_start+1, root_index+1, in_end);
        } else {
            result = NULL;
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
    int preorder_arr[] = {1,2,5,3,4};
    int inorder_arr[] = {2,5,1,4,3};
    vector<int> preorder(preorder_arr, preorder_arr + sizeof(preorder_arr) / sizeof(int));
    vector<int> inorder(inorder_arr, inorder_arr + sizeof(inorder_arr) / sizeof(int));
    TreeNode* root = sol.buildTree(preorder, inorder);
    printBinaryTree(root);
    cout << endl;
}
