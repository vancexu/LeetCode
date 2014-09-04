/* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* res = new ListNode(-1);
        ListNode* node = res;
        int inc = 0;
        while (true) {
            int val = l1->val + l2->val + inc;
            if (val >= 10) {
                val = val - 10;
                inc = 1;
            } else {
                inc = 0;
            }
            node->next = new ListNode(val);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == NULL || l2 == NULL)
                break;
        }
        if (l1 == NULL && l2 == NULL) {
            if (inc == 1) node->next = new ListNode(1);
        } else if (l1 == NULL) {
            if (inc == 0) {
                node->next = l2;
            } else {
                while (true) {
                    int val = l2->val + inc;
                    if (val >= 10) {
                        val = val - 10;
                        inc = 1;
                    } else {
                        inc = 0;
                    }
                    node->next = new ListNode(val);
                    node = node->next;
                    l2 = l2->next;
                    if (l2 == NULL) break;
                }
                if (inc == 1) node->next = new ListNode(1);
            }
        } else { // l2 == NULL
            if (inc == 0) {
                node->next = l1;
            } else {
                while (true) {
                    int val = l1->val + inc;
                    if (val >= 10) {
                        val = val - 10;
                        inc = 1;
                    } else {
                        inc = 0;
                    }
                    node->next = new ListNode(val);
                    node = node->next;
                    l1 = l1->next;
                    if (l1 == NULL) break;
                }
                if (inc == 1) node->next = new ListNode(1);
            }
        }
        return res->next;
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
    ListNode* l1 = makeList({2,4,9});
    ListNode* l2 = makeList({8,2});
    ListNode* sum = sol.addTwoNumbers(l1,l2);
    printList(sum);
}
