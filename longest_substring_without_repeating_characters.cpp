/* Given a string, find the length of the longest substring 
 * without repeating characters. For example, 
 * the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b",
 * with the length of 1. */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int start = 0;
        int current_longest = 0;
        int tmp = 0;
        int last_pos = 0;
        for (int i=0; i < s.size(); ++i) {
            auto found = map.find(s[i]);
            if (found == map.end()) {
                map[s[i]] = i;
                tmp++;
            } else {
                int prev = map[s[i]];
                if (last_pos <= prev)
                    last_pos = prev;
                tmp = i - last_pos;
                map[s[i]] = i;
            }
            if (current_longest < tmp)
                current_longest = tmp;
        }
        return current_longest;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abc") << endl;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("abcdbe") << endl;
    cout << sol.lengthOfLongestSubstring("aa") << endl;
    cout << sol.lengthOfLongestSubstring("abcdefdgbhj") << endl;
    cout << (sol.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco")==12) <<endl;
    cout << endl;
}
