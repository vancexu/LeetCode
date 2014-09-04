/* Given a digit string, return all possible letter combinations that the number could represent. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        map['0'] = " ";
        
        vector<string> res (1, "");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> tempVec;
            for (string str : res) {
                for (char ch : map[digits[i]]) {
                    tempVec.push_back(str+ch);
                }
            }
            res = tempVec;
        }
        return res;
    }

};

int main() {
    Solution sol;
    vector<string> res;
    res = sol.letterCombinations("23");
    for (string s : res) cout << s << endl;
    cout << endl;
}
