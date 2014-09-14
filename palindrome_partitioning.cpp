/* Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 *   [
 *       ["aa","b"],
 *       ["a","a","b"]
 *   ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<string>> res;
        vector<string> tempVec;
        partition(s, res, tempVec);
        return res;
    }

private:
    void partition(string s, vector<vector<string>>& res, vector<string>& tempVec) {
        if (s.empty()) {
            res.push_back(tempVec);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            string left = s.substr(0,i);
            if (isPalindrom(left)) {
                tempVec.push_back(left);
                partition(s.substr(i), res, tempVec);
                tempVec.pop_back();
            }
        }
    }

    bool isPalindrom(const string& s) {
        if (s.empty()) return false;
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1])
                return false;
        }
        return true;
    }
};

void printVecs(vector<vector<string>>& vecs) {
    for (auto vec : vecs) {
        for (string str: vec) 
            cout << str << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<string>> t1 = sol.partition("aaa");
    printVecs(t1);
    cout << endl;
}
