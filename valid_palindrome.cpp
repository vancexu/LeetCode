/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        for (int i = 0; i < s.size(); ++i) {
            if (!isAlphanumeric(s[i])) {
                s.erase(i,1);
                i--;
            }
        }
        for (int i = 0; i < s.size()/2; ++i) {
            if (!isSameCharacter(s[i], s[s.size()-i-1]))
                return false;
        }
        return true;
    }

private:
    bool isAlphanumeric(char ch) {
        return (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9');
    }

    bool isSameCharacter(char ch1, char ch2) {
        return tolower(ch1) == tolower(ch2);
    }
};

int main() {
    Solution sol;
    cout << (true == sol.isPalindrome("A man, a plan, a canal: Panama")) << endl;
    cout << (false == sol.isPalindrome("race a car")) << endl;
    cout << endl;
}
