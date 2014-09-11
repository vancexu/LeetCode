/* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

#include<iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        if (num.empty()) return {};
        vector<vector<int>> res;
        set<vector<int>> prev;
        permute(num, 0, res, prev);
        return res;
    }

private:
    void permute(vector<int>& nums, int begin, vector<vector<int>>& res,
            set<vector<int>>& prev) {
        if (begin == nums.size()) {
            if (!prev.count(nums)) {
                res.push_back(nums);
                prev.insert(nums);
            }
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            permute(nums, begin+1, res, prev);
            swap(nums[begin], nums[i]);
        }
    }
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
    vector<vector<int>> res = sol.permuteUnique(nums);
    printVec(res);
    cout << endl;
}
