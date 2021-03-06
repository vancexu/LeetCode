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
        // visited is only used to avoid unnessary recursive call. 
        // Use size+1 (instead of size) to avoid out of index error when used.
        // visited[i] = false if s.substr(i) won't lead to a word break.
        vector<bool> visited(s.size()+1, true); 
        wordBreakAux(s, dict, 0, tempVec, res, visited);
        return res;
    }

private:
    void wordBreakAux(string s, unordered_set<string>& dict, int start, vector<string>& tempVec, vector<string>& res, vector<bool>& visited) {
        if (start == s.size()) {
            res.push_back(join(tempVec));
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            //cout << "WORD: " << word << endl;
            if (dict.count(word) && visited[i+1]) {
                int previousResultSize = res.size();
                tempVec.push_back(word);
                wordBreakAux(s, dict, i+1, tempVec, res, visited);
                tempVec.pop_back();
                // update visited
                if (res.size() == previousResultSize) 
                    visited[i+1] = false;
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
    string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict1 = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> dict2 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> res1 = sol.wordBreak(s1, dict1);
    //vector<string> res2 = sol.wordBreak(s2, dict2);
    printVec(res1);
    //printVec(res2);
    cout << endl;
}
