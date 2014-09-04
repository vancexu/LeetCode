/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;

        stack<int> s; // store the indexes of hist, each hist is push and pop once
        int maxArea = -1; 
        int top = 0; // record the top of stack
        int barArea = 0; // the area of rect with current bar height
        for (int i = 0; i < height.size();) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i);
                i++;
            } else {
                top = s.top();
                s.pop();
                barArea = height[top] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, barArea);
            }
        }
        while (!s.empty()) {
            top = s.top();
            s.pop();
            barArea = height[top] * (s.empty() ? height.size() : height.size() - s.top() - 1);
            maxArea = max(maxArea, barArea);
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> height = {2,1,5,6,2,3};
    cout << (10 == sol.largestRectangleArea(height)) << endl;
    cout << endl;
}
