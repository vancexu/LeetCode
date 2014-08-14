/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST */

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
    TreeNode* sortedArrayToBST(vector<int>& num) {
        return sortedArrayToBST(num, 0, num.size());
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& num, int low, int high) {
        if (num.empty()) return NULL;
        int n = high - low;
        if (n == 0) return NULL;
        TreeNode* root;
        int offset = low + n/2;
        root = new TreeNode(num[offset]);
        if (n > 1) {
            root->left = sortedArrayToBST(num, low, offset);
            root->right = sortedArrayToBST(num, offset+1, high);
        }
        return root;
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
    int test[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec(test, test + sizeof(test)/sizeof(int));
    printBinaryTree(sol.sortedArrayToBST(vec));
    cout << endl;
}
