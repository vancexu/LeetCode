/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring. */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longest = (!s.empty()) ? 0 : 1;
        int start = 0;
        int end = 0;
        for (int i=0; i<s.size(); ++i) {
            int found = s.rfind(s[i]);
            while (found != string::npos) {
                int n = found - i + 1;
                if (n <= longest) break;
                if (isPalindrome(s, i, found)) {
                    if (longest < n) {
                        longest = n;
                        start = i;
                        end = found;
                    }
                    break;
                } else {
                    found = s.rfind(s[i], found-1);
                }
            }
        }
        return s.substr(start, end-start+1);
    }

private:
    bool isPalindrome(string& s, int low, int high) {
        int n = high - low + 1;
        if (n < 0) return false;
        for (int i=low, j=high; i < low+n/2; ++i,--j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abcdedcghic") << endl;
    cout << sol.longestPalindrome("abcdcbqwertyytre") << endl;
    cout << sol.longestPalindrome("abc") << endl;
    cout << sol.longestPalindrome("abac") << endl;
    cout << sol.longestPalindrome("aaaabaaa") << endl;
    cout << (sol.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") == "ranynar") << endl;
    cout << endl;
}
