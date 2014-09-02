/* Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 *
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 *   All words have the same length.
 *   All words contain only lowercase alphabetic characters.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) return {{start, end}};
        if (dict.empty()) return {};
        unordered_map<string, unordered_set<string> > parents;
        buildGraph(end, start, dict, parents); // parents start from end back to start. 
        vector<vector<string>> paths;
        vector<string> tempVec;
        buildPath(start, end, parents, tempVec, paths);
        return paths;
    }

private:
    /* 
     * Build a directed graph using BFS with level.
     * The graph (stored in parents) is represented by recording all nodes' parents.
     * The root is source, and the last level is sink.
     * The generated graph would be used to generate the word ladder path.
     */
    void buildGraph(string source, string sink, unordered_set<string>& dict, 
            unordered_map<string, unordered_set<string>>& parents) {
        unordered_set<string> visited;       // recored visited words
        unordered_set<string> currentLevel;  
        unordered_set<string> nextLevel;
        
        currentLevel.insert(source);
        bool reachEnd = false;
        while (!currentLevel.empty() && !reachEnd) {
            // marked currentLevel as visited to avoid intra-level reference
            for (string word : currentLevel)
                visited.insert(word);

            for (string word : currentLevel) {
                string newWord = word;
                for (int i = 0; i < word.size(); ++i) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (newWord == sink) reachEnd = true;
                        if (!visited.count(newWord) && (dict.count(newWord) || newWord == sink)) {
                            nextLevel.insert(newWord);
                            parents[newWord].insert(word);
                        }
                    }
                    newWord[i] = word[i];
                }
            }

            currentLevel = nextLevel;
            nextLevel.clear();
        }
    }
    
    /* 
     * using DFS to build word ladder path from generated graph.
     */
    void buildPath(string current, string end, 
            unordered_map<string, unordered_set<string>>& parents,
            vector<string> tempVec, vector<vector<string>>& paths) {
        tempVec.push_back(current);
        if (current == end) {
            paths.push_back(tempVec);
        } else {
            for (string word : parents[current]) {
                buildPath(word, end, parents, tempVec, paths);
            }
        }
        tempVec.pop_back();
    }

    /*
    void printMap(unordered_map<string, unordered_set<string> >& map) {
        for (auto item : map) {
            cout << item.first << ": " << endl;
            printSet(item.second);
        }
    }

    void printSet(unordered_set<string>& s) {
        for (string str : s)
            cout << str << " ";
        cout << endl;
    }
    */

};

void printVecVec(vector<vector<string>>& vecs) {
    for (auto vec : vecs) {
        for (string word : vec) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    vector<vector<string>> res;
    res = sol.findLadders("hit", "cog", dict);
    printVecVec(res);
    cout << endl;
}
