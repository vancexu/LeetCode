/* 
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;

        int N = s.size();
        vector<int> ways(N+1, 0); // ways[i] is the number of decoding ways for s.substr(0,i);
        ways[0] = 1; // dummy num
        if (s[0] != '0') ways[1] = 1;
        
        for (int i = 2; i <= N; ++i) {
            if (s[i-1] != '0')
                ways[i] = ways[i-1];
            int numTwo = stoi(s.substr(i-2,2));
            if (numTwo >= 10 && numTwo <= 26)
                ways[i] += ways[i-2];
        }

        return ways[N];
    }
};

int main() {
    Solution sol;
    cout << sol.numDecodings("230") << endl;
    cout << endl;
}
