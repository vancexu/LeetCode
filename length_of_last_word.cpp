/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char* end = s;
        while (*end) end++;
        end--; // end point to the last character now
        while (end >= s && *end == ' ') end--; // remove pending blanks
        if (end < s) return 0; // spcial case: all blanks "    "
        int res = 0;
        while (end >= s && *end != ' ') {
            end--;
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << (5 == sol.lengthOfLastWord("Hello World")) << endl;
    cout << (5 == sol.lengthOfLastWord(" World ")) << endl;
    cout << (5 == sol.lengthOfLastWord(" Hello World   ")) << endl;
    cout << (0 == sol.lengthOfLastWord("")) << endl;
    cout << endl;
}
