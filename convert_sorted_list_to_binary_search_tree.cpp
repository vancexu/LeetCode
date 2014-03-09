/* Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST. */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* before_mid = &dummy;
        while (before_mid->next != slow)
            before_mid = before_mid->next;
        
        TreeNode* root = new TreeNode(slow->val);
        before_mid->next = NULL;
        root->left = sortedListToBST(dummy.next);
        root->right = sortedListToBST(slow->next);
        return root;
    }

};

ListNode* makeList(vector<int> list) {
    ListNode result(-1);
    ListNode* prev = &result;
    result.next = NULL;
    for (int i : list) {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    return result.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printBST(TreeNode* root) {
    if (root) {
        printBST(root->left);
        cout << root->val << " ";
        printBST(root->right);
    }
}

int main() {
    Solution sol;
    printBST(sol.sortedListToBST(makeList({1,2,3,4,5})));
    printBST(sol.sortedListToBST(makeList({2,3,4,5})));
}
