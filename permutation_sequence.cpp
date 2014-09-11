/*The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (k == 0) return "";
        string candidates = "123456789";
        candidates = candidates.substr(0,n);
        string res(n, ' ');
        for (int i = 0; i < n; ++i) {
            int cases = fac(n-i-1);
            int index = (k-1) / cases;
            res[i] = candidates[index];
            candidates.erase(index,1);
            k = k - index * cases;
        }
        return res;
    }

private:
    int fac(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(4,19) << endl;
    cout << endl;
}
