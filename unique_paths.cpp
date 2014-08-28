/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat (m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) 
            for (int j = 1; j < n; ++j)
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
        return mat[m-1][n-1];
    }
};

int main() {
    Solution sol;
    cout << (3 == sol.uniquePaths(2,3)) << endl;
    cout << (6 == sol.uniquePaths(3,3)) << endl;
    cout << endl;
}
