/** Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists. **/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode* l2) {
        ListNode result(-1);
        ListNode* tail = &result;
        while (true) {
            if (l1 == NULL) {
                tail->next = l2;
                break;
            } else if (l2 == NULL) {
                tail->next = l1;
                break;
            } else if (l1->val <= l2->val) {
                moveNode(&(tail->next), &l1);
            } else {
                moveNode(&(tail->next), &l2);
            }
            tail = tail->next;
        }
        return result.next;
    }
private:
    void moveNode(ListNode** dest, ListNode** source) {
        ListNode* head = *source;
        *source = (*source)->next;
        head->next = *dest;
        *dest = head;
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

int main() {
    Solution sol;
    printList(sol.mergeTwoLists(makeList({1,4,5}), makeList({2,3,6,7})));
}
