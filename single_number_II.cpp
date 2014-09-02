/*Given an array of integers, every element appears three times except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count += ((A[j]>>i) & 1);
            }
            result |= ((count%3)<<i);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int A[] = {1,2,3,3,2,1,1,2,4,3};
    cout << sol.singleNumber(A, 10);
    cout << endl;
}
