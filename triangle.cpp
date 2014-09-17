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
        vector<int> prev(1, triangle[0][0]);
        vector<int> current(2, 0);
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j <=i; ++j) {
                if (j == 0) {
                    current[0] = prev[0] + triangle[i][j];
                } else if (j == i) {
                    current[j] = prev[j-1] + triangle[i][j];
                } else {
                    current[j] = min(prev[j-1], prev[j]) + triangle[i][j];
                }
            }
            prev.swap(current);
            vector<int> next(i+2,0);
            current.swap(next);
        }
        int res = prev[0];
        for (int i = 1; i < M; ++i) {
            res = min(res, prev[i]);
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
