/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 *   Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *   The solution set must not contain duplicate triplets.
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.size() < 3) return {};
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        auto end = num.end();
        for (auto first = num.begin(); first < end-2; first = upper_bound(first, end-2, *first)) {
            for (auto second = first+1; second < end-1; second = upper_bound(second, end-1, *second)) {
                int val = 0 - *first - *second;
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
    vector<int> numbers = {1,2,-2,-1};
    vector<vector<int>> res = sol.threeSum(numbers);
    for (auto vec : res) {
        printVector(vec); 
    }
    cout << endl;
}
