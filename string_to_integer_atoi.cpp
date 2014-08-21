/* Implement atoi to convert a string to an integer. */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        string s(str);
        if (s.empty()) return 0; // no string
        // remove leading blanks
        int i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] != ' ') break;
        }
        s.erase(0,i);
        if (s.empty()) return 0;

        char first = s[0];
        if (s[0] == '+') {
            if (s.size() < 2) return 0; // str == "+"
            return parseInteger(s.substr(1), false);
        } else if (s[0] == '-') {
            if (s.size() < 2) return 0; // str == "-"
            return -1 * parseInteger(s.substr(1), true);
        } else if (isCharANumber(s[0])) {
            return parseInteger(s, false);
        } else {
            return 0; // not number
        }
    }

    bool isCharANumber(char ch) {
        int tmp = ch - '0';
        return tmp >= 0 && tmp <= 9;
    }

    int parseInteger(const string& s, bool isNegative) {
        int res = 0;

        // find the first sequence of numbers
        int i = 0;
        for (; i < s.size(); ++i) 
            if (!isCharANumber(s[i])) break;
        string seq = s.substr(0,i);

        // ignore 0 in first sequence of numbers
        i = 0;
        for (; i < seq.size(); ++i) 
            if (seq[i] != '0') break;
        seq = seq.substr(i);

        // overflow check
        if (seq.size() > 10) 
            return (isNegative) ? INT_MIN : INT_MAX;

        for(int i=0; i < seq.size(); ++i) {
            res += (seq[i]-'0') * pow(10, seq.size()-i-1);
            // overflow check
            if (res < 0) 
                return (isNegative) ? INT_MIN : INT_MAX;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << (1230 == sol.atoi("  +1230 ")) << endl;
    cout << (0 == sol.atoi(" +-8")) << endl;
    cout << (123 == sol.atoi("123")) << endl;
    cout << (123 == sol.atoi("123a")) << endl;
    cout << (1 == sol.atoi(" 1 23")) << endl;
    cout << (123 == sol.atoi("+123")) << endl;
    cout << (123 == sol.atoi("   +123")) << endl;
    cout << (-123 == sol.atoi("-123")) << endl;
    cout << (123 == sol.atoi("0123")) << endl;
    cout << (INT_MAX == sol.atoi("2147483648")) << endl;
    cout << (INT_MAX == sol.atoi("10522545459")) << endl;
    cout << (INT_MIN == sol.atoi("-2147483649")) << endl;
    cout << endl;
}
