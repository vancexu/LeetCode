/* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    bool isScramble(string s1, string s2) {

    }*/

    // first recursive version. Error: Time Limit Exceeded
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string sort_s1 = s1;
        string sort_s2 = s2;
        sort(sort_s1.begin(), sort_s1.end());
        sort(sort_s2.begin(), sort_s2.end());
        if (sort_s1 != sort_s2) return false;
        for (int i=1; i < s1.size(); ++i) {
            string s11 = s1.substr(0,i);
            string s12 = s1.substr(i,s1.size());
            {
                string s21 = s2.substr(0,i);
                string s22 = s2.substr(i,s2.size());
                if (isScramble(s11,s21) && isScramble(s12,s22)) return true;
            }
            {
                string s21 = s2.substr(0,s2.size()-i);
                string s22 = s2.substr(s2.size()-i);
                if (isScramble(s11,s22) && isScramble(s12,s21)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "abcd";
    string s2 = "bdac";
    if (!sol.isScramble(s1,s2)) cout << "pass test 1";
    cout << endl;
}
