/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        if (cols == 0) return;

        // marks[i][j] = true if board[i][j] == 'O' and it is surrounded.
        vector<vector<bool>> marks(rows, vector<bool>(cols, true));
        // BFS queue
        queue<pair<int, int>> q;
        
        // first col
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i,0));
                marks[i][0] = false;
            }
        }
        // first row
        for (int i = 0; i < cols; ++i) {
            if (board[0][i] == 'O') {
                q.push(make_pair(0,i));
                marks[0][i] = false;
            }
        }
        // last col
        for (int i = 0; i < rows; ++i) {
            if (board[i][cols-1] == 'O') {
                q.push(make_pair(i,cols-1));
                marks[i][cols-1] = false;
            }
        }
        // last row
        for (int i = 0; i < cols; ++i) {
            if (board[rows-1][i] == 'O') {
                q.push(make_pair(rows-1, i));
                marks[rows-1][i] = false;
            }
        }

        // BFS
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i > 1 && board[i-1][j] == 'O' && marks[i-1][j]) {
                q.push(make_pair(i-1, j));
                marks[i-1][j] = false;
            }
            if (j > 1 && board[i][j-1] == 'O' && marks[i][j-1]) {
                q.push(make_pair(i, j-1));
                marks[i][j-1] = false;
            }
            if (i < rows-1 && board[i+1][j] == 'O' && marks[i+1][j]) {
                q.push(make_pair(i+1, j));
                marks[i+1][j] = false;
            }
            if (j < cols-1 && board[i][j+1] == 'O' && marks[i][j+1]) {
                q.push(make_pair(i, j+1));
                marks[i][j+1] = false;
            }
        }

        // update board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (marks[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

void printVecs(vector<vector<char>>& vecs) {
    for (auto vec : vecs) {
        for (char c : vec) 
            cout << c << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'O','O','X','X'}};
    sol.solve(board);
    printVecs(board);
    cout << endl;
}
