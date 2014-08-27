/* Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *   The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if (num.empty()) return {};
        vector<int> tmpVec;
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        combinationSumAux(num, target, result, tmpVec, 0);
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
            combinationSumAux(candidates, target - val, result, tmpVec, i+1);
            tmpVec.pop_back();
            while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) i++;
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
    vector<int> can1 = {10,1,2,7,6,1,5};
    vector<vector<int>> t1 = sol.combinationSum2(can1, 8);
    for (auto vec : t1) printVec(vec);
    cout << endl;
}
