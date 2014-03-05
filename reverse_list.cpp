/* Reverse a linked list. Do it in-place and in one-pass. */

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* it = head;
        ListNode* tmp = it->next;
        while (tmp) {
            ListNode* next = tmp->next;
            tmp->next = it;
            if (it == head)
                it->next = NULL;
            it = tmp;
            tmp = next;
        }
        return it;
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
    printList(sol.reverseList(makeList({1,2,3,4,5})));
    printList(sol.reverseList(makeList({1,2})));
}
