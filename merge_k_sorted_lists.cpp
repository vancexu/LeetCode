/** Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. **/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        } else if (lists.size() == 1) {
            return lists[0];
        } else {
            ListNode* first = lists[0];
            for (int i = 1; i < lists.size(); ++i) {
                ListNode* second = lists[i];
                first = mergeTwoLists(first, second);
            }
            return first;
        }
    }

private:
    void moveNode(ListNode** dest, ListNode** source) {
        ListNode* head = *source;
        *source = (*source)->next;
        head->next = *dest;
        *dest = head;
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode* l2) {
        ListNode result(-1);
        ListNode* tail = &result;
        while (true) {
            if (l1 == NULL) {
                tail->next = l2;
                break;
            } else if (l2 == NULL) {
                tail->next = l1;
                break;
            } else if (l1->val <= l2->val) {
                moveNode(&(tail->next), &l1);
            } else {
                moveNode(&(tail->next), &l2);
            }
            tail = tail->next;
        }
        return result.next;
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
    vector<ListNode*> lists = {makeList({1,4,5}), makeList({2,3}), makeList({2,4,6})};
    printList(sol.mergeKLists(lists));
}
