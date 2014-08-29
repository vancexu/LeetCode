/* 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int height = board.size();
        if (height == 0) return false;
        int width = board[0].size();
        if (width == 0) return false;
        if (word.empty()) return true;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (word[0] == board[i][j]) {
                    if (word.size() == 1) return true;
                    else {
                        vector<vector<bool>> mask (height, vector<bool>(width, false));
                        mask[i][j] = true;
                        bool e = existAux(board, word, 1, i, j, mask); 
                        if (e) return true; 
                    }
                }
            }
        }
        return false;
    }
    
    // Given (row,col), return whether there exist word[idx+1] around
    bool existAux(vector<vector<char>>& board, string word, int idx, int row, int col, vector<vector<bool>>& mask) {
        if (idx == word.size()) return true;
        if (row > 0) { 
            int r = row - 1;
            if (board[r][col] == word[idx] && !mask[r][col]) {
                mask[r][col] = true;
                bool e = existAux(board, word, idx+1, r, col, mask);
                if (e) return true;
                else mask[r][col] = false;
            }
        }
        if (row < board.size()-1) {
            int r = row + 1;
            if (board[r][col] == word[idx] && !mask[r][col]) {
                mask[r][col] = true;
                bool e = existAux(board, word, idx+1, r, col, mask);
                if (e) return true;
                else mask[r][col] = false;
            }
        }
        if (col > 0) {
            int c = col - 1;
            if (board[row][c] == word[idx] && !mask[row][c]) {
                mask[row][c] = true;
                bool e = existAux(board, word, idx+1, row, c, mask);
                if (e) return true;
                else mask[row][c] = false;
            }
        }
        if (col < board[0].size()-1) {
            int c = col + 1;
            if (board[row][c] == word[idx] && !mask[row][c]) {
                mask[row][c] = true;
                bool e = existAux(board, word, idx+1, row, c, mask);
                if (e) return true;
                else mask[row][c] = false;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'a','b','c','e'}, {'s','f','c','s'}, {'a','d','e','e'}};
    cout << (true == sol.exist(board, "abcced")) << endl;
    cout << (true == sol.exist(board, "see")) << endl;
    cout << (false == sol.exist(board, "abcb")) << endl;
    cout << (false == sol.exist(board, "esfc")) << endl;
    vector<vector<char>> b2 = {{'A','B','C','E'}, {'S','F','E','S'}, {'A','D','E','E'}};
    cout << (true == sol.exist(b2, "ABCESEEEFS")) << endl;
    cout << endl;
}
