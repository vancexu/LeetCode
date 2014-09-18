/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        stack<int> stack; // push '(' index  to stack
        int res = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else { // s[i] == ')'
                if (stack.empty()) {
                    start = i + 1;
                    continue;
                } else {
                    stack.pop();
                    res = stack.empty() ? max(res, i-start+1) : max(res, i-stack.top());
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.longestValidParentheses("()((())(");
    cout << endl;
}
