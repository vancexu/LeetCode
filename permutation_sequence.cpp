/*The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (k == 0) return "";
        vector<int> nums;
        for (int i = 1; i <= n; ++i)
            nums.push_back(i);
        vector<int> res;
        vector<int> tmpVec(n, 0);
        unordered_set<int> prev;
        permuteAux(nums, res, tmpVec, 0, prev, k);
        return join(res);
    }

private:
    string join(vector<int>& vec) {
        string res = "";
        for (int item : vec)
            res += to_string(item);
        return res;
    }

    // Using similiar method as Combinations.cpp
    // HOWEVER, even though it passed LeetCode tests, it assumes nums has no duplicate numbers.
    void permuteAux(vector<int>& nums, vector<int>& res,
            vector<int>& tmpVec, int level, unordered_set<int>& prev, int& k) {
        if (level == nums.size()) {
            k--;
            if (k == 0) 
                res = tmpVec;
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (prev.count(nums[i]))
                continue;

            tmpVec[level] = nums[i];
            prev.insert(nums[i]);
            permuteAux(nums, res, tmpVec, level+1, prev, k);
            prev.erase(nums[i]);
        }
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(3,4) << endl;
    cout << endl;
}
