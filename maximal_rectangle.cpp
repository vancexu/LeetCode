/* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        if (width == 0) return 0;
        
        int maxRect = -1;
        vector<int> prevHist(width, 0);
        for (int row = 0; row < height; ++row) {
            vector<int> hist(width, 0);
            for (int col = 0; col < width; ++col) {
                if (matrix[row][col] == '1')
                    hist[col] = prevHist[col] + 1;
            }
            maxRect = max(maxRect, largestRectangleArea(hist));
            prevHist = hist;
        }
        return maxRect;
    }

private:
    int largestRectangleArea(vector<int>& hist) {
        if (hist.empty()) return 0;

        stack<int> s;
        int top = 0;
        int maxRect = -1;
        int barArea = 0;
        for (int i = 0; i < hist.size(); ) {
            if (s.empty() || hist[i] >= hist[s.top()]) {
                s.push(i);
                i++;
            } else {
                top = s.top();
                s.pop();
                barArea = hist[top] * (s.empty() ? i : i - s.top() - 1);
                maxRect = max(barArea, maxRect);
            }
        }
        while (!s.empty()) {
            top = s.top();
            s.pop();
            barArea = hist[top] * (s.empty() ? hist.size() : hist.size() - s.top() - 1);
            maxRect = max(barArea, maxRect);
        }
        return maxRect;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> mat = {{'0','1','0','1'}, {'1','1','0','1'},{'0','1','1','1'}};
    cout << (3 == sol.maximalRectangle(mat)) << endl;
    cout << endl;
}
