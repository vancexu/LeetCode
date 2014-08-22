/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum. */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int curMax = A[0];
        for (int i=1; i < n; ++i) {
            curMax = max(A[i], curMax+A[i]);
            res = max(res, curMax);
        }
        return res;
    }
};

int main () {
    Solution sol;
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout << (6 == sol.maxSubArray(A, 9)) << endl;
    cout << endl;
}
