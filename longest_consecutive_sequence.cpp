/* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if (num.size() < 2) return num.size();
        unordered_set<int> set;
        for (int item : num) 
            set.insert(item);
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            int left = num[i];
            int right = num[i];
            int tmp = 1;
            set.erase(num[i]);  // erase is important here, it saves a lot.
            while (set.count(left-1)) {
                set.erase(left);
                left--;
                tmp++;
            }
            while (set.count(right+1)) {
                set.erase(right);
                right++;
                tmp++;
            }
            res = max(res, tmp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    cout << sol.longestConsecutive(nums) << endl;
    cout << endl;
}
