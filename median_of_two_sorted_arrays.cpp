/* There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)). */

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m < n) return findMedianSortedArrays(A, m, B, n, 0, m-1);
        else return findMedianSortedArrays(B, n, A, m, 0, n-1);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n, int low, int high) {
        if (low > high) 
            return findMedianSortedArrays(B, n, A, m, max(0, (m+n)/2-m), min(n, (m+n)/2));
        int i = (low + high) / 2;
        int j = (m + n) / 2 - i - 1;
        if (j >= 0 && A[i] < B[j])
            return findMedianSortedArrays(A, m, B, n, i+1, high);
        else if (j < n-1 && A[i] > B[j+1])
            return findMedianSortedArrays(A, m, B, n, low, i-1);
        else {
            cout << "i: " << i << " j: " << j << endl; 
            if ((m+n)%2 == 1) return A[i];
            else if (j < 0) return (A[i] + A[i-1]) / 2.0;
            else return (A[i] + B[j]) / 2.0;
        }
    }
};

int main() {
    Solution sol;
    int A[] = {};
    int B[] = {2,3};
    cout << sol.findMedianSortedArrays(A, 0, B, 2) << endl;
    cout << endl;
}
