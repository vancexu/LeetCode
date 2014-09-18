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

        // num of minimal candies for each child
        vector<int> left(N, 1); 
        vector<int> right(N, 1); 

        for (int i = 1; i < N; ++i) {
            if (ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }

        for (int i = N-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
        }

        int res = 0;
        for (int i = 0; i < N; ++i)
            res += max(left[i], right[i]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {8,9,3,5,1,2,7,6,10};
    vector<int> ratings2 = {1,2,2};
    vector<int> ratings3 = {2,2,1};
    cout << sol.candy(ratings) << endl;
    cout << sol.candy(ratings2) << endl;
    cout << sol.candy(ratings3) << endl;
    cout << endl;
}
