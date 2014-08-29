/*Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (dict.empty()) return {};
        if (s.empty()) return {};
        vector<string> res;
        vector<string> tempVec;
        wordBreakAux(s, dict, 0, tempVec, res);
        return res;
    }

private:
    void wordBreakAux(string s, unordered_set<string>& dict, int start, vector<string>& tempVec, vector<string>& res) {
        if (start == s.size()) {
            res.push_back(join(tempVec));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            //cout << "WORD: " << word << endl;
            if (dict.count(word)) {
                tempVec.push_back(word);
                wordBreakAux(s, dict, i+1, tempVec, res);
                tempVec.pop_back();
            }
        }
    }

    string join(vector<string>& vec) {
        string res = "";
        for (int i = 0; i < vec.size(); ++i) {
            if (i < vec.size()-1)
                res = res + vec[i] + " ";
            else 
                res = res + vec[i];
        }
        return res;   
    }
};

void printVec(vector<string> vec) {
    for (string word : vec)
        cout << word << endl;
}

int main() {
    Solution sol;
    string s1 = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = sol.wordBreak(s1, dict);
    printVec(res);
    cout << endl;
}
