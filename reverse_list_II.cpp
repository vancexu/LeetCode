/* Reverse a linked list from position m to n. Do it in-place and in one-pass. 
 * 1 ≤ m ≤ n ≤ length of list. */

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* startNode = &dummy;
        for (int i = 0; i < m-1; ++i) startNode = startNode->next;
        ListNode* nodeM = startNode;
        ListNode* it = startNode->next;
        ListNode* tmp = it->next;
        for (int i = 0; i < n-m; ++i) {
            ListNode* next = tmp->next;
            tmp->next = it;
            it = tmp;
            tmp = next;
        }
        nodeM->next->next = tmp;
        nodeM->next = it;
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
    printList(sol.reverseBetween(makeList({1,2,3,4,5}),2,4));
    printList(sol.reverseBetween(makeList({1,2,3,4,5}),1,4));
    printList(sol.reverseBetween(makeList({1,2,3,4,5}),2,5));
    printList(sol.reverseBetween(makeList({1,2,3,4,5}),1,5));
}
