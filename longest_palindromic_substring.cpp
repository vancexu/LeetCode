/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring. */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = (s.empty()) ? "" : s.substr(0,1);
        for (int i=0; i < s.size()-1; ++i) {
            string s1 = expandAroundCenter(s, i, i);
            if (longest.size() < s1.size()) 
                longest = s1;
            string s2 = expandAroundCenter(s, i, i+1);
            if (longest.size() < s2.size())
                longest = s2;
        }
        return longest;
    }

private:
    string expandAroundCenter(string& s, int c1, int c2) {
        int l = c1;
        int r = c2;
        while ((l >= 0) && (r <= s.size()-1) && (s[l] == s[r])) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abcdedcghic") << endl;
    cout << sol.longestPalindrome("abcdcbqwertyytre") << endl;
    cout << sol.longestPalindrome("abc") << endl;
    cout << sol.longestPalindrome("a") << endl;
    cout << sol.longestPalindrome("abac") << endl;
    cout << sol.longestPalindrome("aaaabaaa") << endl;
    cout << (sol.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") == "ranynar") << endl;
    cout << endl;
}
