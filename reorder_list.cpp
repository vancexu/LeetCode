/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* it_right = reverseList(slow->next);
        slow->next = NULL;
        ListNode* it_left = head;
        while (it_right) {
            ListNode* tmp_left = it_left->next;
            ListNode* tmp_right = it_right->next;
            it_left->next = it_right;
            it_right->next = tmp_left;
            it_left = tmp_left;
            it_right = tmp_right;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* it = head;
        ListNode* before_it = &dummy;
        while (it) {
            ListNode* next = it->next;
            if (it == head)
                it->next = NULL;
            else
                it->next = before_it;
            before_it = it;
            it = next;
        }
        return before_it;
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
    ListNode* test = makeList({1,2,3,4});
    printList(test);
    sol.reorderList(test);
    printList(test);
}
