/* Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int>> res;
        vector<int> tempVec;
        subsets(S, res, tempVec, 0);
        return res;
    }

private:
    void subsets(vector<int>& vec, vector<vector<int>>& res, 
                 vector<int> tempVec, int start) {
        if (start == vec.size()) {
            res.push_back(tempVec);
            return;
        }
        tempVec.push_back(vec[start]);
        subsets(vec, res, tempVec, start+1);
        tempVec.pop_back();
        subsets(vec, res, tempVec, start+1);
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
    vector<int> v = {1,2,3};
    vector<vector<int>> res = sol.subsets(v);
    printVecs(res);
    cout << endl;
    cout << res.size() << endl;
}
