/* Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode* left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (root == NULL) return;
        vector<TreeLinkNode*> cur = {root};
        while (!cur.empty()) {
            vector<TreeLinkNode*> next;
            for (int i = 0; i < cur.size()-1; ++i) {
                cur[i]->next = cur[i+1];
                if (cur[i]->left) {
                    next.push_back(cur[i]->left);
                    next.push_back(cur[i]->right);
                }
            }
            if (cur.back()->left) {
                next.push_back(cur.back()->left);
                next.push_back(cur.back()->right);
            }
            cur = next;
        }
    }
};

int main() {
    Solution sol;
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    sol.connect(root); 
    cout << endl;
}
