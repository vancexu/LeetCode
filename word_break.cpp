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
        bool res = false;
        for (string word : dict) {
            int it = s.find(word);
            if (it != string::npos) {
                res = wordBreak(s.erase(it, word.size()), dict);
                if (res) break;
            }
        }
        return res;
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
