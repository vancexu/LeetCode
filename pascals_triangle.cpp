/* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i+1, 1);
            res.push_back(row);
        }
        for (int i = 1; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }

};

void printVecs(vector<vector<int>>& vecs) {
    for (auto vec : vecs) {
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> res = sol.generate(5);
    printVecs(res);
    cout << endl;
}
