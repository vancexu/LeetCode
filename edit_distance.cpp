/* 
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> mat(len1+1, vector<int>(len2+1,0));
        for (int i = 1; i <= len2; ++i)
            mat[0][i] = i;
        for (int i = 1; i <= len1; ++i)
            mat[i][0] = i;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i-1] == word2[j-1])
                    mat[i][j] = mat[i-1][j-1];
                else 
                    mat[i][j] = min(mat[i-1][j-1], min(mat[i][j-1], mat[i-1][j])) + 1;
            }
        }

        return mat[len1][len2];
    }
};

int main() {
    Solution sol;
    cout << sol.minDistance("cat", "acats");
    cout << endl;
}
