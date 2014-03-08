/* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (head == NULL) return head;

        // for each node, add a copy as its next
        RandomListNode* it = head;
        RandomListNode* next;
        while (it) {
            next = it->next;
            it->next = new RandomListNode(it->label);
            it->next->next = next;
            it = next;
        }
        
        // set random pointer for copied nodes
        it = head;
        RandomListNode* new_it = it->next;
        while (it) {
            if (it->random) {
                new_it->random = it->random->next;
            }
            it = new_it->next;
            if (it)
                new_it = it->next;
        }
        
        // get copy list and recover origin list
        RandomListNode dummy(0);
        dummy.next = head->next;
        it = head;
        new_it = dummy.next;
        while (it) {
            it->next = new_it->next;
            if (it->next)
                new_it->next = it->next->next;
            it = it->next;
            new_it = new_it->next;
        }
        return dummy.next;
        
    }
};

RandomListNode* makeList(vector<int> list) {
    RandomListNode result(-1);
    RandomListNode* prev = &result;
    result.next = NULL;
    for (int i : list) {
        prev->next = new RandomListNode(i);
        prev = prev->next;
    }
    return result.next;
}

void printList(RandomListNode* head) {
    while (head) {
        cout << head->label << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    printList(sol.copyRandomList(makeList({3,2,1,4,5})));
}
