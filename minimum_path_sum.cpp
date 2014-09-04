/* Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which 
 * minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time. */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int> > mat(vector<vector<int> >(m, vector<int>(n, 0)));
        mat[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) mat[i][0] = mat[i-1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) mat[0][j] = mat[0][j-1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] = min(mat[i-1][j], mat[i][j-1]) + grid[i][j];
            }
        }
        return mat[m-1][n-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int> > grid = {{1,2,3},{6,5,4},{3,2,1}};
    cout << (11 == sol.minPathSum(grid)) << endl;
    cout << endl;
}
