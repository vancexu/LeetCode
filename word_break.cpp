/* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.empty()) return false;
        if (s.empty()) return true;
        if (s.size() == 1) return dict.count(s);
        // inDict[i] = true iff s.sub(0,i+1) in dict
        vector<bool> inDict(s.size(), false);
        inDict[0] = dict.count(s.substr(0,1));
        for (int i = 1; i < s.size(); ++i) {
            inDict[i] = dict.count(s.substr(0, i+1));
            if (inDict[i]) continue;
            // looking for whether partition existed
            for (int k = 0; k < i; ++k) {
                bool res = inDict[k] && dict.count(s.substr(k+1,i-k));
                if (res) {
                    inDict[i] = true;
                    break;
                }
            }
        }
        return inDict[s.size()-1];
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    string s2 = "leetcodeleet";
    string s3 = "leetcodeleetcodes";
    string s4 = "dogs";
    unordered_set<string> dict = {"leet", "code"};
    unordered_set<string> dict2 = {"dog", "s", "gs"};
    cout << (true == sol.wordBreak(s1, dict)) << endl;
    cout << (true == sol.wordBreak(s2, dict)) << endl;
    cout << (false == sol.wordBreak(s3, dict)) << endl;
    cout << (true == sol.wordBreak(s4, dict2)) << endl;
    cout << endl;
}
