/* There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int N = ratings.size();
        if (N == 1) return 1;
        vector<int> nums(N, 0); // num of candies for each child
        candy(nums, ratings, 0, N-1); 
        int res = 0;
        for (int n : nums)
            res += n;
        return res;
    }

    void candy(vector<int>& nums, vector<int>& ratings, 
               int low, int high) {
        if (low > high) {
            return;
        }
        int min_rating = ratings[low];
        int min_index = low;
        for (int i = low; i <= high; ++i) {
            if (min_rating > ratings[i]) {
                min_index = i;
                min_rating = ratings[i];
            }
        }
        if (min_index == 0) 
            nums[min_index] = nums[min_index+1] + 1;
        else if (min_index == ratings.size()-1)
            nums[min_index] = nums[min_index-1] + 1;
        else
            nums[min_index] = max(nums[min_index-1], nums[min_index+1]) + 1;
        candy(nums, ratings, low, min_index-1);
        candy(nums, ratings, min_index+1, high);
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {8,9,3,5,1,2,7,6,10};
    cout << sol.candy(ratings);
    cout << endl;
}
