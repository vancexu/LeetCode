/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy_small(0);
        ListNode dummy_large(0);
        ListNode* small = &dummy_small;
        ListNode* large = &dummy_large;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = head;
            } else {
                large->next = head;
                large = head;
            }
            head = head->next;
        }
        large->next = NULL;
        small->next = dummy_large.next;
        return dummy_small.next;
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
    printList(sol.partition(makeList({1,4,3,2,5,2}), 3));
}
