/* Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int n) : val(n), next(NULL) {};
};

class LRUCache {
    unordered_map<int,int> contents; // key->values
    ListNode* dummy;
    ListNode* tail;
    int size;
    const int totalCap;

private:
    void updateList(int key) {
        ListNode* node = dummy->next;
        ListNode* prev = dummy;
        while (node) {
            if (node->val != key) {
                prev = node;
                node = node->next;
            } else {
                if (node->next == NULL) break;
                prev->next = node->next;
                node->next = NULL;
                tail->next = node;
                tail = node;
                break;
            }
        }
    }

public:
    LRUCache(int capacity) : size(0), totalCap(capacity) {
        dummy = new ListNode(INT_MIN);
        tail = dummy;
    }

    int get(int key) {
        if (contents.count(key)) {
            updateList(key);
            return contents[key];
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        if (contents.count(key)) {
            contents[key] = value;
            updateList(key);
        } else { // new key
            contents[key] = value;
            tail->next = new ListNode(key);
            tail = tail->next;
            if (size < totalCap) {
                size++;
            } else { // delete head node 
                dummy->next = dummy->next->next;
            }
        }
    }

    void printList() {
        ListNode* node = dummy->next;
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    LRUCache c(3);
    c.set(1,1);
    c.printList();
    c.set(2,2);
    c.printList();
    c.get(1);
    c.printList();
    c.set(3,3);
    c.printList();
    c.get(3);
    c.printList();
    c.set(4,4);
    c.printList();
    cout << endl;
   
}
