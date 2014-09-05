/* Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) {
            x = -1 * x;
            isNeg = true;
        }

        int digit = 0;
        int rev = 0;
        int num = x;
        while (num > 0) {
            digit = num % 10;
            rev = rev * 10 + digit;
            num = num / 10;
        }
        
        return isNeg ? -1 * rev : rev;
    }
};

int main() {
    Solution sol;
    cout << (0 == sol. reverse(0)) << endl;
    cout << (321 == sol.reverse(123)) << endl;
    cout << (-321 == sol.reverse(-123)) << endl;
    cout << (1 == sol.reverse(100)) << endl;
    cout << endl;
}
