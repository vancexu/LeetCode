/** Sort a linked list in O(n log n) time using constant space complexity **/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* similar algorithm to merge sort */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        } else {
            ListNode* front;
            ListNode* back;
            splitList(head, &front, &back);
            front = sortList(front);
            back = sortList(back);
            return merge(front, back);
        }
    }
private:
    /* remove the head node from source, and put it front of dest,
     * then update the head of dest list */
    void moveNode(ListNode** dest, ListNode** source) {
        ListNode* n = *source;
        if (n == NULL) return;
        *source = (*source)->next;
        n->next = *dest;
        *dest = n;
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode result(-1); // dummy node
        ListNode* tail = &result;
        result.next = NULL;
        while (true) {
            if (a == NULL) {
                tail->next = b;
                break;
            } else if (b == NULL) {
                tail->next = a;
                break;
            } else if (a->val <= b->val) {
                moveNode(&(tail->next), &a);
            } else {
                moveNode(&(tail->next), &b);
            }
            tail = tail->next;
        }
        return result.next;
    }

    void splitList(ListNode* source, ListNode** front, ListNode** back) {
        if (source == NULL || source->next == NULL) {
            *front = source;
            *back = NULL;
        } else {
            ListNode* slow = source;
            ListNode* fast = source->next;
            while (fast) {
                fast = fast->next;
                if (fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            *back = slow->next;
            slow->next = NULL;
            *front = source;
        }
    }
};

ListNode* makeList(vector<int> list) {
    ListNode result(-1); // dummpy node
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
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = makeList({6,2,4,7,3,1,5,8});
    printList(sol.sortList(head));
}

