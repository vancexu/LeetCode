/* Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.empty()) return 0;
        // using BFS
        unordered_set<string> visited;
        visited.insert(start);
        queue<pair<string, int>> q; // using <string,int> pair to record the len
        q.push({start, 1});
        while (!q.empty()) {
            auto item = q.front();
            q.pop();
            string word = item.first;
            for (int i = 0; i < word.size(); ++i) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    
                    if (word == end) return item.second + 1; // end found
                    if (dict.count(word) && !visited.count(word)) { // trans found and continue
                        q.push({word, item.second+1});
                        visited.insert(word);
                    }
                }
                word = item.first;
            }
        }
        return 0;
    }

};

int main() {
    Solution sol;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", dict);
    cout << endl;
}
