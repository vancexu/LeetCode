/* Given postorder and inorder traversal of a tree, construct the binary tree. 
 * assume that duplicates do not exist in the tree.
 * */

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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* result;
        for (int i=0; i<inorder.size(); ++i) 
            this->hashmap_inorder[inorder[i]] = i;
        result = buildTree(inorder, postorder, postorder.size(), 0, inorder.size());
        return result;
    }

private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int post_end, int in_start, int in_end) {
        TreeNode* result;
        if (in_end - in_start >= 1) {
            result = new TreeNode(postorder[post_end-1]);
            int root_index = hashmap_inorder[postorder[post_end-1]];
            result->left = buildTree(inorder, postorder, post_end-1-(in_end-root_index-1), in_start, root_index);
            result->right = buildTree(inorder, postorder, post_end-1, root_index+1, in_end); 
        } else {
            result = NULL;
        }
        return result;
    }
};

void printBinaryTree(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printBinaryTree(root->left);
        printBinaryTree(root->right);
    }
}

int main() {
    Solution sol;
    int postorder_arr[] = {5,2,4,3,1};
    int inorder_arr[] = {2,5,1,4,3};
    vector<int> postorder(postorder_arr, postorder_arr + sizeof(postorder_arr) / sizeof(int));
    vector<int> inorder(inorder_arr, inorder_arr + sizeof(inorder_arr) / sizeof(int));
    TreeNode* root = sol.buildTree(inorder, postorder);
    printBinaryTree(root);
    cout << endl;
}
