/*Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        int len = 0;
        ListNode* node = head;
        while (node) {
            len++;
            node = node->next;
        }
        if (len < 2) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevStart = dummy;
        ListNode* start = head;
        ListNode* end;
        ListNode* afterEnd;
        for (int i = 0; i < len/2; ++i) {
            end = start->next;
            if (end) {
                afterEnd = end->next;
                end->next = start;
                start->next = afterEnd;
                prevStart->next = end;
                prevStart = start;
                start = afterEnd;
            }
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
    printList(sol.swapPairs(makeList({1,2,3,4,5})));
}
