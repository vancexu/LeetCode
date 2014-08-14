/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n? */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> vec(n+1,1);
        for (int i=2; i<=n; ++i) {
            int result = 0;
            for (int j=0; j<i; ++j) {
                result += vec[j]*vec[i-j-1];
            }
            vec[i] = result;
        }
        return vec[n];
    }
};

int main() {
    Solution sol;
    cout << sol.numTrees(2) << endl;
    cout << sol.numTrees(3) << endl;
}
