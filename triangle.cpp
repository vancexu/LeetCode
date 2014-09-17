/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        const int M = triangle.size();
        vector<vector<int>> mat;
        for (int i = 1; i <= M; ++i) {
            vector<int> vec(i,0);
            mat.push_back(vec);
        }
        mat[0][0] = triangle[0][0];
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    mat[i][j] = mat[i-1][j] + triangle[i][j];
                } else if (j == i) {
                    mat[i][j] = mat[i-1][j-1] + triangle[i][j];
                } else {
                    mat[i][j] = min(mat[i-1][j-1], mat[i-1][j]) + triangle[i][j];
                }
            }
        }
        int res = mat[M-1][0];
        for (int i = 1; i < M; ++i) {
            res = min(res, mat[M-1][i]);
        }
        return res;
    }

    void printVecs(vector<vector<int>>& vecs) {
        for (auto vec : vecs) {
            for (int i : vec)
                cout << i << " ";
            cout << endl;
        }
    }

};

int main() {
    Solution sol;
    vector<vector<int>> tri = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout << sol.minimumTotal(tri) << endl;
    cout << endl;
}
