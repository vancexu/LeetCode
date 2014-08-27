/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *   The solution set must not contain duplicate quadruplets.
 *
 *   Thanks to @KavinYao for helpping me with these sum series problems.
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
        int quad[4];
        const int n = num.size();

        for (int first=0; first < n-3; ++first) {
            // skip duplicates
            if (first > 0 && num[first-1] == num[first]) continue;

            for (int second=first+1; second < n-2; ++second) {
                // skip duplicates
                if (second > first+1 && num[second-1] == num[second]) continue;

                int third = second + 1;
                int fourth = n - 1;
                while (third < fourth) {
                    int sum = num[third] + num[fourth];
                    int newTarget = target - num[first] - num[second];
                    if (sum == newTarget) {
                        res.push_back({num[first], num[second], num[third], num[fourth]});
                        do {
                            third++;
                        } while (third < fourth && num[third-1] == num[third]);
                        do {
                            fourth--;
                        } while (fourth > third && num[fourth] == num[fourth+1]);
                    } else if (sum < newTarget) {
                        third++;
                    } else {
                        fourth--;
                    }
                }
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
