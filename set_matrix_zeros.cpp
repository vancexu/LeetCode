/* 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        if (cols == 0) return;

        // use first row and col to mark, the following two var used to recover
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                first_col_has_zero = true;
                break;
            }
        }
        for (int i = 0; i < cols; ++i) {
            if (matrix[0][i] == 0) {
                first_row_has_zero = true;
                break;
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; ++j)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 1; i < cols; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < rows; ++j)
                    matrix[j][i] = 0;
            }
        }

        if (first_row_has_zero) {
            for (int i = 0; i < cols; ++i)
                matrix[0][i] = 0;
        }
        if (first_col_has_zero) {
            for (int i = 0; i < rows; ++i)
                matrix[i][0] = 0;
        }

    }
};

int main() {
    Solution sol;

    cout << endl;
}
