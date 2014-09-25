/* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4) return {};
        vector<vector<string>> parts;
        vector<string> tempVec;
        restore(s, 0, parts, tempVec);
        return join(parts);
    }

private:
    vector<string> join(vector<vector<string>>& parts) {
        vector<string> res;
        for (auto vec : parts) {
            stringstream ss;
            for (string s : vec) 
                ss << s << '.';
            string s = ss.str();
            s = s.substr(0, s.size()-1);
            res.push_back(s);
        }
        return res;
    }

    void restore(string s, int start,
                 vector<vector<string>>& parts, vector<string>& tempVec) {
        if (tempVec.size() > 4) {
            return;
        }
        if (tempVec.size() == 4 && start == s.size()) {
            parts.push_back(tempVec);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (start + i > s.size())
                break;
            if (i >= 2 && s[start] == '0') // deal with special case like X.010.X
                break;
            string part = s.substr(start, i);
            int part_num = stoi(part);
            if (part_num > 255) 
                break;
            tempVec.push_back(part);
            restore(s, start+i, parts, tempVec);
            tempVec.pop_back();
        }
    }
    
    void printVecs(vector<vector<string>>& vecs) {
        for (auto vec : vecs) {
            for (string s : vec)
                cout << s << ".";
            cout << endl;
        }
    }
};

void printVec(vector<string> vec) {
    for (string s : vec)
        cout << s << endl;
}

int main() {
    Solution sol;
    string s = "010010";
    vector<string> res;
    res = sol.restoreIpAddresses(s);
    printVec(res);
    cout << endl;
}
