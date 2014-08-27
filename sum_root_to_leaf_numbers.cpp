/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        vector<vector<int>> result;
        vector<int> tempVec;
        sumNumbersAux(root, result, tempVec);
        int s = 0;
        for (auto vec : result) {
            removeFrontZeros(vec);
            // printVector(vec);
            int tmp = convertVecToInt(vec);
            // cout << tmp << endl;
            s += tmp;
        }
        return s;
    }

private:
    void removeFrontZeros(vector<int>& vec) {
        if (convertVecToInt(vec) == 0) return; // deal with special case {0} etc.
        int i = 0;
        while (i < vec.size()) {
            if (vec[i] != 0) break;
            i++;
        }
        vec.erase(vec.begin(), vec.begin()+i);
    }

    void printVector(vector<int>& vec) {
        for (int item : vec)
            cout << item << " ";
        cout << endl;
    }

    int convertVecToInt(vector<int>& vec) {
        if (vec.empty()) return 0;
        int res = 0;
        for (int i=0; i < vec.size(); ++i) {
            res += vec[i] * pow(10,vec.size()-i-1);
        }
        return res;
    }

    void sumNumbersAux(TreeNode* root, vector<vector<int>>& result, vector<int>& tempVec) {
        if (root == NULL) return;
        tempVec.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(tempVec);
            tempVec.pop_back();
            return;
        } else {
            sumNumbersAux(root->left, result, tempVec);
            sumNumbersAux(root->right, result, tempVec);
        }
        tempVec.pop_back();
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(0);
    /*
    root->left = new TreeNode(9);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(3);
    */
    cout << sol.sumNumbers(root) << endl;
    cout << endl;
}
