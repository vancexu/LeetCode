/* There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)). */

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2 == 1)
            return findKthElement(A, m, B, n, (m+n)/2+1);
        else {
            int m1 = findKthElement(A, m, B, n, (m+n)/2);
            int m2 = findKthElement(A, m, B, n, (m+n)/2+1);
            return (m1+m2) / 2.0;
        }
    }

private:
    /*
     * Find the kth smallest element in merged sorted array A and B.
     * assume m <= n, m >= 0, n >= 0, k > 0;
     */
    double findKthElement(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKthElement(B, n, A, m, k); // A is shorter than B
        if (m == 0) return B[k-1]; // ignore A
        if (k == 1) return min(A[0], B[0]); 
        
        int pa = min(m, k/2);
        int pb = k - pa;
        if (A[pa-1] < B[pb-1]) // kth element not in A[0,pa)
            return findKthElement(A+pa, m-pa, B, n, k-pa);
        else if (A[pa-1] > B[pb-1]) // kth element not in B[0,pb)
            return findKthElement(A, m, B+pb, n-pb, k-pb);
        else // A[pa] == B[pb]
            return A[pa-1];
    }
};

int main() {
    Solution sol;
    int A1[] = {1,2,3,4};
    int B1[] = {3,4,5,6};
    cout << (3.5 == sol.findMedianSortedArrays(A1, 4, B1, 4)) << endl;
    int A2[] = {};
    int B2[] = {3,4,5,6};
    cout << (4.5 == sol.findMedianSortedArrays(A2, 0, B2, 4)) << endl;
    int A3[] = {};
    int B3[] = {3,4,5};
    cout << (4.0 == sol.findMedianSortedArrays(A3, 0, B3, 3)) << endl;
    cout << endl;
}
