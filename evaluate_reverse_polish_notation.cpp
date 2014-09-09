/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<string> s;
        unordered_set<string> ops = {"+","-","*","/"};
        for (string token : tokens) {
            if (ops.count(token) == 0) // push number in stack
                s.push(token);
            else { // 
                string a2 = s.top(); 
                s.pop();
                string a1 = s.top();
                s.pop();
                string newToken = compute(a1,a2,token);
                s.push(newToken);
            }
        }
        return stoi(s.top());
    }

private:
    string compute(string a1, string a2, string token) {
        int n1 = stoi(a1);
        int n2 = stoi(a2);
        if (token == "+")
            return to_string(n1+n2);
        if (token == "-")
            return to_string(n1-n2);
        if (token == "*")
            return to_string(n1*n2);
        if (token == "/")
            return to_string(n1/n2);
        return "";
    }
};

int main() {
    Solution sol;
    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << sol.evalRPN(tokens1) << endl;
    cout << endl;
}
