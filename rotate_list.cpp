/* Given a list, rotate the list to the right by k places, where k is non-negative. */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) 
            return head;
        int length = 0;
        ListNode* it = head;
        while (it) {
            it = it->next;
            length++;
        }
        k = k % length;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 0; i < k; ++i) first = first->next;
        if (first == NULL || first == head) return head;
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        dummy.next = second->next;
        first->next = head;
        second->next = NULL;
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
    printList(sol.rotateRight(makeList({1,2,3,4,5}), 2));
    printList(sol.rotateRight(makeList({1,2,3,4,5}), 1));
    printList(sol.rotateRight(makeList({1,2,3,4,5}), 5));
}
