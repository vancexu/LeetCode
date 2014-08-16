/* Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            slow = slow->next;
            if (fast->next) fast = fast->next->next;
            else return false;
            if (slow == NULL || fast == NULL) return false;
            if (slow == fast) return true;
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

int main() {
    Solution sol;
    ListNode* list = makeList({1,2,3,4});
    cout << sol.hasCycle(list) << endl;

    ListNode* tail = list;
    while (tail->next) tail = tail->next;
    tail->next = new ListNode(5);
    tail = tail->next;
    tail->next = list;
    cout << sol.hasCycle(list) << endl;
}
