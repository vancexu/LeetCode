/* Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int N = T.size();
        int M = S.size();
        // mat[i][j] is num of distinct seq of T[0:i] in S[0:j];
        vector<vector<int>> mat(N+1, vector<int>(M+1, 0));
        
        for (int i = 0; i < N+1; ++i) mat[i][0] = 0;
        for (int i = 0; i < M+1; ++i) mat[0][i] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                mat[i][j] = mat[i][j-1];
                if (T[i-1] == S[j-1]) {
                    mat[i][j] += mat[i-1][j-1];
                }
            }
        }
        return mat[N][M];
    }
};

int main() {
    Solution sol;
    cout << sol.numDistinct("aabb", "abb") << endl;
    cout << endl;
}
