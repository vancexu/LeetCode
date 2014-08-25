/* Given two sorted integer arrays A and B, merge B into A as one sorted array. */

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int p = 0; p < n; ++p) A[p] = B[p];
            return;
        }
        int i = 0;
        int j = 0;
        int C[m+n];
        int k = 0;
        while (true) {
            if (A[i] <= B[j]) {
                C[k++] = A[i++];
                if (i == m) break;
            } else {
                C[k++] = B[j++];
                if (j == n) break;
            }
        }
        if (i == m) {
            while (j < n) C[k++] = B[j++];
        }
        if (j == n) {
            while (i < m) C[k++] = A[i++];
        }
        for (int p = 0; p < m+n; ++p) A[p] = C[p];
        return;
    }
};

int main() {
    Solution sol;
    int A[] = {};
    int B[] = {3,4,5,6};
    sol.merge(A,0,B,4);
    for (int i=0; i<4; ++i) cout << A[i] << " ";
    cout << endl;
}
