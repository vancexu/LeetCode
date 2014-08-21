/* You are given a string, S, and a list of words, L, 
 * that are all of the same length. 
 * Find all starting indices of substring(s) in S 
 * that is a concatenation of each word in L exactly once 
 * and without any intervening characters. */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        if (L.empty()) return {};
        int len = L[0].size();
        int num = L.size();
        if (len*num > S.size()) return {};

        vector<int> res;
        unordered_map<string,int> map;
        for (string word: L)
            map[word]++;
        for (int i=0; i+num*len-1 < S.size(); ++i) {
            unordered_map<string,int> tmpmap;
            int j = 0;
            for (; j < num; ++j) {
                string sub = S.substr(i+j*len, len);
                if (!map.count(sub)) {
                    break;
                } else {
                    tmpmap[sub]++;
                    if (tmpmap[sub] > map[sub])
                        break;
                }
            }
            if (j == num)
                res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> v = {"in", "at", "up"};
    vector<int> res = sol.findSubstring("atinuptupinatupmninupat", v);
    for (int r:res) cout << r << " ";
    cout << endl;
}
