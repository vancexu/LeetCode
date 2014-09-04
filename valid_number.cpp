/*Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * define valid number as: 
     *      \s*
     *      [+-]?
     *      (\d+(\.\d*) | \.\d+)
     *      ([eE][+-]?\d+)?
     *      \s*
     * where \s is space
     */
    bool isNumber(const char *s) {
        // strip leading space
        while (*s && *s == ' ') s++;
        
        // + - sign
        if (*s == '+' || *s == '-') s++;

        // decimal
        bool hasDecimal = false;
        while (*s && *s >= '0' && *s <= '9') {
            hasDecimal = true;
            s++;
        }

        // fractional
        bool hasFractional = false;
        if (*s && *s == '.') {
            s++;
            while (*s && *s >= '0' && *s <= '9') {
                hasFractional = true;
                s++;
            }
        }

        if (!hasDecimal && !hasFractional)
            return false;

        // exponential
        if (*s && (*s == 'e' || *s == 'E')) {
            s++;
            // sign
            if (*s && (*s == '+' || *s == '-')) {
                s++;
            }
            bool hasExp = false;
            while (*s && *s >= '0' && *s <= '9') {
                hasExp = true;
                s++;
            }

            if (!hasExp) 
                return false;
        }

        // strip ending space
        while (*s && *s == ' ') s++;

        return *s == '\0';
    }
};

int main() {
    Solution sol;
    cout << (true == sol.isNumber("0")) << endl;
    cout << (true == sol.isNumber(" 0.1 ")) << endl;
    cout << (false == sol.isNumber("abc")) << endl;
    cout << (false == sol.isNumber("1 a")) << endl;
    cout << (true == sol.isNumber("2e10")) << endl; 
    cout << endl;
}
