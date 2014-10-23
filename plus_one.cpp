/* Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {1};
        int inc = 0;
        int n = digits.size();
        vector<int> res(n+1, 0);

        int s = digits[n-1] + 1;
        if (s == 10) {
            res[n] = 0;
            inc = 1;
        } else {
            res[n] = s;
            inc = 0;
        }

        for (int i = n-2; i >= 0; --i) {
            int s = inc + digits[i];
            if (s == 10) {
                res[i+1] = 0;
                inc = 1;
            } else {
                res[i+1] = s;
                inc = 0;
            }
        }

        if (inc == 1) {
            res[0] = 1;
        } else {
            res.erase(res.begin());
        }

        return res;
    }
};


void printVec(vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    Solution sol;
    vector<int> test = {9,9,9};
    vector<int> res = sol.plusOne(test);
    printVec(res);
    cout << endl;
}
