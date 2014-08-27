/* Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *   The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) return {};
        vector<int> tmpVec;
        vector<vector<int> > result;
        // sort(candidates.begin(), candidates.end(), greater<int>()); // This would be faster, but the system wrongly declined the answer.
        combinationSumAux(candidates, target, result, tmpVec, 0);
        return result;
    }

private:
    void combinationSumAux(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& tmpVec, int level) {
        if (target == 0) {
            result.push_back(tmpVec);
            return;
        } else if (target < 0) {
            return;
        }
        for (int i = level; i < candidates.size(); ++i) {
            int val = candidates[i];
            tmpVec.push_back(val);
            combinationSumAux(candidates, target - val, result, tmpVec, i);
            tmpVec.pop_back();
        }
    }
};

void printVec(vector<int>& vec) {
    for (int item : vec)
        cout << item << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> can1 = {2,3,6,7};
    vector<vector<int>> t1 = sol.combinationSum(can1, 7);
    for (auto vec : t1) printVec(vec);
    cout << endl;
}
