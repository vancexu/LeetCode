/* Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) return 0;

        int maxi = 1; // keep track of maximal product of contiguous subarray
        int mini = 1; // keep track of minimal product of comtiguous subarray
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            maxi = max(maxi, 1);
            if (A[i] > 0) {
                maxi = maxi * A[i];
                mini = mini * A[i];
            } else { // A[i] <= 0
                int tmp = maxi;
                maxi = mini * A[i];
                mini = tmp * A[i];
            }
            res = max(res, maxi);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int A[] = {0,-2};
    cout << sol.maxProduct(A, 1) << endl;
    cout << endl;
}
