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
        if (S.empty()) return 0;
        int res = 0;
        numDistinctAux(S, T, res);
        return res;
    }

    void numDistinctAux(string s, string t, int& res) {
        if (t.empty()) {
            res++;
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == t[0]) {
                    numDistinctAux(s.substr(i+1), t.substr(1), res);
                }
            }
        }
    }
};

int main() {
    Solution sol;
    cout << sol.numDistinct("aabb", "abb") << endl;
    cout << endl;
}
