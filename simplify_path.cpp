/* Given an absolute path for a file (Unix-style), simplify it. 
 * For example,
 *   path = "/home/", => "/home"
 *   path = "/a/./b/../../c/", => "/c"
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> items; 

        split(path, '/', items);
        // remove empty and "."
        for (int i = 0; i < items.size(); ++i) {
            if (items[i] == "." || items[i] == "") { 
                items.erase(items.begin()+i);
                i--;
            }
        }
        // deal with ".."
        for (int i = 1; i < items.size(); ++i) {
            if (items[i] == ".." && i >= 1) {
                items.erase(items.begin()+i-1,items.begin()+i+1);
                i -= 2;
            }
        }

        string result = "";
        // deal with stupid case: "/home/../../.."
        items.erase(remove(items.begin(), items.end(), ".."), items.end());
        if (items.empty()) 
            result =  "/";
        else {
            for (string item : items)
                result = result + "/" + item;
        }
        return result;        
    }

private:
    void split(const string& s, char delim, vector<string>& result) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
            result.push_back(item);
    }
};

int main() {
    Solution sol;
    string s1 = "/a/./b/..//../c/";
    string s2 = "/home/";
    string s3 = "/home/../../..";
    string s4 = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    cout << ("/c" == sol.simplifyPath(s1)) << endl;
    cout << ("/home" == sol.simplifyPath(s2)) << endl;
    cout << ("/" == sol.simplifyPath(s3)) << endl;
    cout << ("/e/f/g" == sol.simplifyPath(s4)) << endl;
    cout << endl;
}
