/* Determine whether an integer is a palindrome. Do this without extra space.*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x / 10 == 0) return true;
        int num = x;
        int digit = 0;
        int reverse = 0;
        while (num > 0) {
            digit = num % 10;
            reverse = reverse * 10 + digit;
            num = num / 10;
        }
        return reverse == x;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome(12321) << endl;
    cout << sol.isPalindrome(1221) << endl;
    cout << sol.isPalindrome(1) << endl;
    cout << sol.isPalindrome(12210) << endl;

    cout << endl;
}
