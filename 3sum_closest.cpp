/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        int closestDiff = INT_MAX;
        sort(num.begin(), num.end());
        for (int first = 0; first < num.size()-2; ++first) {
            int second = first+1;
            int third = num.size()-1;
            while (second < third) {
                int sum = num[first] + num[second] + num[third];
                if (sum == target)
                    return target;
                int diff = target - sum;
                if (abs(closestDiff) > abs(diff))
                    closestDiff = diff;
                if (diff > 0) 
                    second++;
                else 
                    third--;
            }
        }
        return target - closestDiff;
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {-1,2,1,-4};
    cout << (2 == sol.threeSumClosest(numbers, 1));
    cout << endl;
}
