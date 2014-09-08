/* Divide two integers without using multiplication, division and mod operator. */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return -1;
        if (divisor == 1) return dividend;
        if (divisor == -1) return 0 - dividend;

        unsigned int divd = dividend;
        unsigned int divs = divisor;
        if (dividend < 0) divd = ~divd + 1;
        if (divisor < 0) divs = ~divs + 1;

        int res = 0;
        int count = 1;
        while (divd > divs) {
            divs = divs << 1;
            count = count << 1;
        }
        while (count > 0) {
            if (divd >= divs) {
                divd = divd - divs;
                res += count;
            }
            divs = divs >> 1;
            count = count >> 1;
        }
        return (dividend>0 ^ divisor>0)? 0 - res : res;
    }
};

int main() {
    Solution sol;
    cout << (5 == sol.divide(5,1)) << endl;
    cout << (0 == sol.divide(0,2)) << endl;
    cout << (2 == sol.divide(5,2)) << endl;
    cout << (-5 == sol.divide(-15,3)) << endl;
    cout << (-5 == sol.divide(15,-3)) << endl;
    cout << (3 == sol.divide(-10,-3)) << endl;
    cout << (1073741823 == sol.divide(2147483647,2)) << endl;
    cout << endl;
}
