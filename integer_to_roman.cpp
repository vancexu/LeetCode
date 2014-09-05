/* Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res;
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                res.append(symbols[i]);
                num -= values[i];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << (sol.intToRoman(3999) == "MMMCMXCIX") << endl;
    cout << (sol.intToRoman(9) == "IX") << endl;
    cout << endl;
}
