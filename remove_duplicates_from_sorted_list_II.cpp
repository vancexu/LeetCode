/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* it = head;
        ListNode* before_it = &dummy;
        bool isDuplicate = false;
        while (it->next) {
            if (it->next->val == it->val) {
                it->next = it->next->next;
                isDuplicate = true;
            } else {
                if (isDuplicate) {
                    before_it->next = it->next;
                } else {
                    before_it = it;
                }
                it = it->next;
                isDuplicate = false;
            }
        }
        if (isDuplicate) {
            before_it->next = it->next;
        }
        return dummy.next;
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
    printList(sol.deleteDuplicates(makeList({1,2,3,3,4,4,5})));
    printList(sol.deleteDuplicates(makeList({1,1,1,2,3})));
    printList(sol.deleteDuplicates(makeList({1,1})));
    printList(sol.deleteDuplicates(makeList({1,2,2})));
}
