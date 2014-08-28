/* Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return -1;
        int n = obstacleGrid[0].size();
        if (n == 0) return -1;

        if (obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> mat (m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) break;
            mat[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) break;
            mat[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    mat[i][j] = 0;
                else 
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0}, {0,1,0}, {0,0,0}};
    cout << (2 == sol.uniquePathsWithObstacles(grid)) << endl;
    cout << endl;
}
