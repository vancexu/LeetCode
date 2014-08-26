/* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. */

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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if (root == NULL) return {};
        vector<vector<int> > result;
        vector<int> tmp;
        pathSumAux(root, sum, tmp, result);
        return result;
    }

private:
    void pathSumAux(TreeNode* root, int sum, vector<int>& tmpVec, vector<vector<int> >& result) {
        if (root == NULL) return;
        tmpVec.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum)
                result.push_back(tmpVec);
        } else {
                pathSumAux(root->left, sum - root->val, tmpVec, result);
                pathSumAux(root->right, sum - root->val, tmpVec, result);
        }
        tmpVec.pop_back();
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    vector<vector<int> > test =  sol.pathSum(root, 7);
    for (auto vec: test) {
        for (auto item: vec) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
}
