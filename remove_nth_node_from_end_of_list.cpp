/* Given a linked list, remove the nth node from the end of list and return its head. 
 * Given n will always be valid.
 * Try to do this in one pass. */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 0; i < n; ++i) first = first->next;
        if (first == NULL) { // remove head
            return head->next;
        }
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
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
    printList(sol.removeNthFromEnd(makeList({1,2,3,4,5}), 2));
    printList(sol.removeNthFromEnd(makeList({1,2,3,4,5}), 5));
    printList(sol.removeNthFromEnd(makeList({1,2,3,4,5}), 1));
}
