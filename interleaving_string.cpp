/* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == "" && s2 == "" && s3 == "") return true;
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > mat(s1.size()+1, vector<bool>(s2.size()+1, false));
        mat[0][0] = true;
        for (int i=1; i <= s1.size(); ++i)
            mat[i][0] = s1[i-1] == s3[i-1];
        for (int i=1; i <= s2.size(); ++i)
            mat[0][i] = s2[i-1] == s3[i-1];
        for (int i=1; i <= s1.size(); ++i) {
            for (int j=1; j <= s2.size(); ++j) {
                mat[i][j] = (mat[i][j-1] && s2[j-1]==s3[i+j-1]) || (mat[i-1][j] && s1[i-1]==s3[i+j-1]);
            }
        }
        return mat[s1.size()][s2.size()];
    }

    // Recursive, time limit exceeded
    /*
    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == "" && s2 == "" && s3 == "") return true;
        if (s1.size() + s2.size() != s3.size()) return false;
        string new_s3 = s3.substr(1);
        if (s3[0] == s1[0] && s3[0] == s2[0]) {
            return isInterleave(s1.substr(1), s2, new_s3) || isInterleave(s1, s2.substr(1), new_s3);
        } else if (s3[0] == s1[0]) {
            return isInterleave(s1.substr(1), s2, new_s3);
        } else if (s3[0] == s2[0]) {
            return isInterleave(s1, s2.substr(1), new_s3);
        } else {
            return false;
        }
    }
    */
};

int main() {
    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << sol.isInterleave("aa", "ab", "aaba") << endl;
    cout << endl;
}
