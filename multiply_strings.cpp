/* Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string n1 = reverseString(num1);
        string n2 = reverseString(num2);
        string res = "0";
        if (n1.size() < n2.size()) n1.swap(n2); // n1 is the longer num
        vector<string> intermediate(n2.size(), "");
        for (int i=0; i<n2.size(); ++i) {
            int p2 = n2[i] - '0';
            int inc = 0;
            string tmp(n1.size()+1,'0');
            for (int j=0; j<n1.size(); ++j) {
                int p1 = n1[j] - '0';
                int m = p1 * p2 + inc;
                tmp[j] = (m % 10) + '0';
                inc = m / 10;
            }
            if (inc == 0) tmp.erase(n1.size(), 1);
            else tmp[n1.size()] = inc +'0';
            tmp = reverseString(tmp);
            for (int k=0; k < i; ++k)
                tmp += '0';
            intermediate[i] = tmp;
        }
        for (int i=0; i < intermediate.size(); ++i) {
            res = add(res, intermediate[i]);
        }
        return res;
    }
    
    string add(string num1, string num2) {
        int inc = 0;
        int len_min = min(num1.size(), num2.size());
        int len_max = max(num1.size(), num2.size());
        string n1 = reverseString(num1);
        string n2 = reverseString(num2);
        string res(len_max+1, '0');
        for (int i=0; i<len_min; ++i) {
            int p1 = n1[i] - '0';
            int p2 = n2[i] - '0';
            int sum = p1 + p2 + inc;
            if (sum >= 10) {
                res[i] = (sum-10) + '0';
                inc = 1;
            } else {
                res[i] = (sum) + '0';
                inc = 0;
            }
        }
        for (int i=len_min; i<len_max; ++i) {
            string n;
            if (len_max == n1.size()) n = n1;
            else n = n2;
            int p = n[i] - '0';
            int sum = p + inc;
            if (sum >= 10) {
                res[i] = (sum-10) + '0';
                inc = 1;
            } else {
                res[i] = (sum) + '0';
                inc = 0;
            }
        }
        if (inc == 1) {
            res[len_max] = '1';
        } else {
            res.erase(len_max, 1);
        }
        return reverseString(res);
    }

    string reverseString(string s) {
        if (s.empty()) return "";
        int n = s.size();
        for (int i=0; i<n/2; ++i) {
            char tmp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = tmp;
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.add("1234","40") << endl;
    cout << sol.add("99", "3214") << endl;
    cout << sol.add("99", "1") << endl;
    cout << sol.multiply("99", "1") << endl;
    cout << sol.multiply("99", "999") << endl;
    cout << sol.multiply("50", "10") << endl;
    cout << sol.multiply("50", "0") << endl;
    cout << endl;
}
