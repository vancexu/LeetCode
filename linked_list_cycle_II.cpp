/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    ListNode* detectCycle(ListNode* head) {
       map<ListNode*, bool> visited;
       ListNode* node = head;
       while (node) {
           auto it = visited.find(node);
           if (it == visited.end()) {
               visited[node] = true;
           } else {
               return it->first;
           }
           node = node->next;
       }
       return NULL;
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
