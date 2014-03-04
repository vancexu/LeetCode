/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // find the collision point
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }
        // deal with non cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        // find the start point of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
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

int main() {
    Solution sol;
    ListNode* list = makeList({1,2,3,4});
    cout << sol.detectCycle(list) << endl;

    ListNode* tail = list;
    while (tail->next) tail = tail->next;
    tail->next = new ListNode(5);
    tail = tail->next;
    tail->next = list;
    cout << (sol.detectCycle(list))->val << endl;
}
