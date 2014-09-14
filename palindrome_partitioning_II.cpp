/* Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        const int N = s.size();
        vector<int> res(N, 0); // res[i] is mincuts of s.substr(0,i+1);
        for (int i = 0; i < N; ++i)
            res[i] = i; // initialize mincuts to the biggest possible cuts.
        
        // mat[i][j] = true if s[i:j] is palindrome. Using DP
        vector<vector<bool>> mat(N, vector<bool>(N, false));
        for (int i = N-1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (i == j) {
                    mat[i][j] = true;
                } else if (j - i == 1) {
                    mat[i][j] = s[i] == s[j];
                } else {
                    mat[i][j] = (mat[i+1][j-1] && s[i] == s[j]);
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            if (mat[0][i]) {
                res[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (mat[j+1][i]) {
                        res[i] = min(res[i], res[j]+1);
                    } 
                }
            }
        }
        return res[N-1];
    }
};

int main() {
    Solution sol;
    cout << sol.minCut("leet") << endl;
    cout << sol.minCut("aab") << endl;
    cout << endl;
}
