/* Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice? */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int prev = A[0];
        int idx = 1;
        int newIdx = 1;
        while (true) {
            if (idx < n && prev == A[idx]) {
                swap(A[idx], A[newIdx]);
                idx++;
                newIdx++;
            }
            while (idx < n && prev == A[idx]) idx++;
            if (idx == n) break;
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
    int A[] = {1,1,1,1,2,2,3,4,4,4,5};
    cout << (8 == sol.removeDuplicates(A, 11)) << endl;
    for (int i=0; i<8; ++i) cout << A[i] << " ";
    cout << endl;
    int B[] = {1,1,1,1};
    cout << (2 == sol.removeDuplicates(B,4)) << endl;
    for (int i=0; i<2; ++i) cout << B[i] << " ";
    cout << endl;
}
