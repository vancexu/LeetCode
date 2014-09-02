/*Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i < n; ++i) {
            A[i] = A[i] ^ A[i-1];
        }
        return A[n-1];
    }
};

int main() {
    Solution sol;
    int A[] = {2,1,1,2,3,4,4,6,5,5,6};
    cout << sol.singleNumber(A, 11);
    cout << endl;
}
