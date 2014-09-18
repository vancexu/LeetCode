/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res;
        vector<int> tempVec;
        set<vector<int>> existed;
        subsets(S, res, tempVec, 0, existed);
        return res;
    }

private:
    void subsets(vector<int>& vec, vector<vector<int>>& res, 
                 vector<int> tempVec, int start, 
                 set<vector<int>>& existed) {
        if (start == vec.size()) {
            if (existed.count(tempVec) == 0) {
                existed.insert(tempVec);
                res.push_back(tempVec);
            }
            return;
        }
        tempVec.push_back(vec[start]);
        subsets(vec, res, tempVec, start+1, existed);
        tempVec.pop_back();
        subsets(vec, res, tempVec, start+1, existed);
    }
};

void printVecs(vector<vector<int>>& vecs) {
    for (auto vec : vecs) {
        for (int i : vec) 
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<int> v = {1,2,2};
    vector<vector<int>> res = sol.subsetsWithDup(v);
    printVecs(res);
    cout << endl;
    cout << res.size() << endl;
}
