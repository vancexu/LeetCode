/* Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        if (num.empty()) return {};
        vector<vector<int>> res;
        //vector<int> tmpVec(num.size(), 0);
        //unordered_set<int> prev;
        //permuteAux(num, res, tmpVec, 0, prev);
        permute(num, 0, res);
        return res;
    }

private:
    void permute(vector<int>& num, int begin, vector<vector<int>>& res) {
        if (begin == num.size()) {
            res.push_back(num);
            return;
        }
        for (int i = begin; i < num.size(); ++i) {
            swap(num[begin], num[i]);
            permute(num, begin+1, res);
            swap(num[begin], num[i]);
        }
    }

    // Using similiar method as Combinations.cpp
    // HOWEVER, even though it passed LeetCode tests, it assumes nums has no duplicate numbers.
    /*
    void permuteAux(vector<int>& nums, vector<vector<int>>& res,
            vector<int>& tmpVec, int level, unordered_set<int>& prev) {
        if (level == nums.size()) {
            res.push_back(tmpVec);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (prev.count(nums[i]))
                continue;

            tmpVec[level] = nums[i];
            prev.insert(nums[i]);
            permuteAux(nums, res, tmpVec, level+1, prev);
            prev.erase(nums[i]);
        }
    }
    */
};

void printVec(vector<vector<int>>& vecs) {
    for (auto vec : vecs) {
        for (int item : vec)
            cout << item << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = sol.permute(nums);
    printVec(res);
    cout << endl;
}
