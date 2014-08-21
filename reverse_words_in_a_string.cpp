/* Given an input string, reverse the string word by word. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string& s) {
        if (s.empty()) return;
        string res;
        vector<string> words = split(s);
        for (int i = words.size()-1; i >= 0; --i) {
            res += words[i];
            if (i != 0)
                res += " ";
        }
        s = res;
    }

private:
    vector<string> split(string s) {
        if (s.empty()) return {};
        vector<string> words;
        vector<int> blankIndexes;
        for (int i=0; i < s.size(); ++i)
            if (s[i] == ' ')
                blankIndexes.push_back(i);

        if (blankIndexes.empty()) {
            words.push_back(s);
        } else {
            if (blankIndexes[0] != 0) 
                words.push_back(s.substr(0,blankIndexes[0]));
            for (int i=0; i < blankIndexes.size()-1; ++i) {
                int cur = blankIndexes[i];
                int next = blankIndexes[i+1];
                if (next - cur > 1) 
                    words.push_back(s.substr(cur+1, next-cur-1));
            }
            if (blankIndexes.back() != s.size()-1)
                words.push_back(s.substr(blankIndexes.back()+1));
        }
        return words;
    }
};

int main() {
    Solution sol;
    string s1 = "the sky is blue";
    string s2 = "  the sky  is blue  ";
    string s3 = " ";
    string s4 = "a";
    sol.reverseWords(s1);
    sol.reverseWords(s2);
    sol.reverseWords(s3);
    sol.reverseWords(s4);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << endl;
}
