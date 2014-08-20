/* Given a string S and a string T, 
 * find the minimum window in S which will contain all the characters in T in complexity O(n). */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.empty()) return "";
        unordered_map<char,int> needToFind;
        unordered_map<char,int> hasFound;
        for (char ch: T) {
            if (needToFind.count(ch) == 0) {
                needToFind[ch] = 1;
            } else {
                needToFind[ch] += 1;
            }
        }
        for (char ch: T)
            hasFound[ch] = 0;
        int found = 0;
        int begin = 0;
        int end = 0;
        string res = S;
        for (; end < S.size(); ++end) {
            if (needToFind.count(S[end]) == 0) // skip char not in T
                continue;
            hasFound[S[end]]++;
            if (hasFound[S[end]] <= needToFind[S[end]])
                found++;

            if (found == T.size()) {
                bool con1 = (needToFind.count(S[begin]) == 0);
                bool con2 = false;
                if (!con1) // needToFind[ch] will create a new element, so check exist first.
                    con2 = (hasFound[S[begin]] > needToFind[S[begin]]);
                while (con1 || con2) {
                    if (con2) {
                        hasFound[S[begin]]--;
                    }
                    begin++;
                    con1 = (needToFind.count(S[begin]) == 0);
                    if (!con1) con2 = (hasFound[S[begin]] > needToFind[S[begin]]);
                    else con2 = false;
                }

                if (res.size() > end-begin+1) {
                    res = S.substr(begin, end-begin+1);
                }
            }
        }
        if (found != T.size()) res = "";
        return res;
    }
};

int main() {
    Solution sol;
    cout << (sol.minWindow("acbbaca", "aba") == "baca") << endl;
    cout << (sol.minWindow("adobecodebanc", "abc") == "banc") << endl;
    cout << (sol.minWindow("aa", "aa") == "aa") << endl;
    cout << endl;
}
