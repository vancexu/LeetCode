/* Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {

static map<char, int> mapping;

public:
    /* 
     * Start from the first roman digit, 
     * if it is bigger than previous digit, plus current digit but minus previous;
     * else plus curent digit.
     */
    int romanToInt(string s) {
        if (s.empty()) return 0;

        int res = mapping[s[0]];
        for (int i = 1; i < s.size(); ++i) {
            if (mapping[s[i]] > mapping[s[i-1]])
                res += mapping[s[i]] - 2*mapping[s[i-1]];
            else 
                res += mapping[s[i]];
        }

        return res;
    }
};

map<char, int> Solution::mapping = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

int main() {
    Solution sol;
    cout << (3999 == sol.romanToInt("MMMCMXCIX")) << endl;
    cout << (9 == sol.romanToInt("IX")) << endl;
    cout << (621 == sol.romanToInt("DCXXI")) << endl;
    cout << endl;
}
