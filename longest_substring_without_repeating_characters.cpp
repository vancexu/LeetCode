/* Given a string, find the length of the longest substring 
 * without repeating characters. For example, 
 * the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b",
 * with the length of 1. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        string sub = s.substr(0,s.size()-1);
        size_t found = sub.rfind(s[s.size()-1]);
        int len = lengthOfLongestSubstring(sub);
        if (found == string::npos)
            return max(len, int(s.size()));
        else 
            return max(len, int(s.substr(found+1).size()));
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abc") << endl;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("abcdbe") << endl;
    cout << sol.lengthOfLongestSubstring("aa") << endl;
    cout << endl;
}
