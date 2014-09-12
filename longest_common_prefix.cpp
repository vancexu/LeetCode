/* Write a function to find the longest common prefix string amongst an array of strings. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int shortest = strs[0].size();
        string start = strs[0];
        for (string s : strs) {
            if (s.size() < shortest) {
                shortest = s.size();
                start = s;
            }
        }
        for (string s : strs) {
            start = longestCommonPrefix(s, start);
        }
        return start;
    }

private:
    string longestCommonPrefix(string s1, string s2) {
        if (s1.size() > s2.size()) s1.swap(s2);
        int i = 0;
        for (; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                break;
        }
        return s1.substr(0, i);
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"abcdefg", "abcdwwefg", "abcdcdcd", "abcqws", "abn"};
    cout << sol.longestCommonPrefix(strs);
    cout << endl;
}
