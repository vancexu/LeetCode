/* Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 * You may only use constant extra space.
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
                if (cur[i]->left) 
                    next.push_back(cur[i]->left);
                if (cur[i]->right)
                    next.push_back(cur[i]->right);
                
            }
            if (cur.back()->left) 
                next.push_back(cur.back()->left);
            if (cur.back()->right)
                next.push_back(cur.back()->right);
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
