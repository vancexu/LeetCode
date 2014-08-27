/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *   The solution set must not contain duplicate quadruplets.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return {};
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        for (auto it=num.begin(); it < num.end()-3; it=upper_bound(it,num.end()-3,*it)) {
            vector<vector<int>> three = threeSum(num, target-*it, it-num.begin()+1);
            for (int i=0; i < three.size(); ++i)
                three[i].insert(three[i].begin(), *it);
            res.insert(res.end(), three.begin(), three.end());
        }
        return res;
    }

private:
    vector<vector<int> > threeSum(vector<int> &num, int target, int start) {
        if (num.size() < 3) return {};
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        auto end = num.end();
        for (auto first = num.begin()+start; first < end-2; first = upper_bound(first, end-2, *first)) {
            for (auto second = first+1; second < end-1; second = upper_bound(second, end-1, *second)) {
                int val = target - *first - *second;
                if (binary_search(second+1, end, val)) 
                    res.push_back({*first, *second, val});
            }
        }
        return res;
    }
};

void printVector(vector<int> vec) {
    for (int item : vec) 
        cout << item << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> numbers = {1,0,-1,0,-2,2};
    vector<vector<int>> res = sol.fourSum(numbers, 0);
    for (auto vec : res) {
        printVector(vec); 
    }
    cout << endl;
}
