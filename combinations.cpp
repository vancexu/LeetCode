/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. */

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k <= 0) return {};
        vector<vector<int>> res;
        vector<int> tmpVec;
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) 
            numbers.push_back(i);
        combineAux(numbers, k, res, tmpVec, 0);
        return res;
    }

    void combineAux(vector<int>& nums, int k, vector<vector<int>>& res,
            vector<int>& tmpVec, int level) {
        if (k == 0) {
            res.push_back(tmpVec);
            return;
        }
        for (int i = level; i < nums.size(); ++i) {
            tmpVec.push_back(nums[i]);
            combineAux(nums, k-1, res, tmpVec, i+1);
            tmpVec.pop_back();
        }
    }
};

void printVec(vector<vector<int>>& vecs) {
    for (auto vec : vecs) {
        for (int item : vec) 
            cout << item << " ";
        cout << endl;
    }
    cout << endl;
}
int main() {
    Solution sol;
    vector<vector<int>> res = sol.combine(4,3);
    printVec(res);
    cout << endl;
}
