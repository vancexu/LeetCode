/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int len = 0;
        for (ListNode* n = head; n != NULL; n = n->next)
            len++;
        int groups = len / k;
        ListNode* groupPrev = dummy;
        for (int i = 0; i < groups; ++i) {
            ListNode* groupEnd = groupPrev;
            for (int j = 0; j < k; ++j)
                groupEnd = groupEnd->next;
            ListNode* groupEndNext = groupEnd->next;
            ListNode* groupStart = groupPrev->next;
            if (groupStart != NULL) {
                ListNode* it = groupStart->next;
                ListNode* prev = groupStart;
                for (int j = 1; j < k; ++j) {
                    ListNode* tmp = it->next;
                    it->next = prev;
                    prev = it;
                    it = tmp;
                }
                groupStart->next = groupEndNext;
            }
            groupPrev->next = groupEnd;
            groupPrev = groupStart;
        }
        return dummy->next;
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
    ListNode* test1 = makeList({1,2,3,4,5,6});
    ListNode* test2 = makeList({1,2,3,4,5,6});
    ListNode* test3 = makeList({1,2,3,4,5,6});
    printList(sol.reverseKGroup(test1, 2));
    printList(sol.reverseKGroup(test2, 3));
    printList(sol.reverseKGroup(test3, 4));
}
