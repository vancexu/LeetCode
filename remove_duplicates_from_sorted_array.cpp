/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int prev = A[0];
        int idx = 1;
        int newIdx = 1;
        while (true) {
            while (idx < n && A[idx] == prev)
                idx++;
            if (idx == n) break; // all same, like "1111"
            swap(A[idx], A[newIdx]);
            prev = A[newIdx];
            idx++;
            newIdx++;
        }
        return newIdx;
    }
};

int main() {
    Solution sol;
    int A[] = {1,2,2,3,4,4,5,5};
    cout << (5 == sol.removeDuplicates(A, 8)) << endl;
    for (int i = 0; i < 5; ++i) cout << A[i] << " ";
    cout << endl;
    int B[] = {1,1,1,1};
    cout << (1 == sol.removeDuplicates(B, 4)) << endl;
    for (int i = 0; i < 1; ++i) cout << A[i] << endl;
    cout << endl;
}
