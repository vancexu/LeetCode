/* Sort a linked list using insertion sort. */

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        } else {
            ListNode dummy(INT_MIN);
            dummy.next = head;
            ListNode* cur = head->next; // the current node we are checking
            ListNode* before_cur = head;
            ListNode* prev = &dummy; // prev->next points to the insertion node
            while (cur != NULL) {
                ListNode* it = prev->next;
                while ((it != cur) && (cur->val >= it->val)) {
                    prev = it;
                    it = it->next;
                }
                if (it == cur) {
                    before_cur = cur;
                    cur = cur->next;
                } else {
                    ListNode* tmp = cur;
                    before_cur->next = cur->next;
                    cur = cur->next;
                    tmp->next = it;
                    prev->next = tmp;
                }
                prev = &dummy;
            }
            return dummy.next;
        }
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
    printList(sol.insertionSortList(makeList({2,1})));
    printList(sol.insertionSortList(makeList({3,4,1})));
    printList(sol.insertionSortList(makeList({1,3,5,2,4})));
    printList(sol.insertionSortList(makeList({5,4,3,2,1})));
}
