/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        
        // for each column, record the highest height at its left
        int tmpMax = INT_MIN;
        int leftHighest[n];
        for (int i = 0; i < n; ++i) {
            leftHighest[i] = max(A[i], tmpMax);
            tmpMax = leftHighest[i];
        }
        // for each column, record the highest height at its right
        tmpMax = INT_MIN;
        int rightHighest[n];
        for (int i = n-1; i >= 0; --i) {
            rightHighest[i] = max(A[i], tmpMax);
            tmpMax = rightHighest[i];
        }
        // the lower height of two sides minus the height itself, is the water it traps.
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += min(leftHighest[i], rightHighest[i]) - A[i];
        }
        return result;
    }

};

int main() {
    Solution sol;
    int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(A, sizeof(A)/sizeof(A[0])) << endl;
}
