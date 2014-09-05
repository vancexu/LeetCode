/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res = 0;
        int n = prices.size();
        
        // split prices as [0,i], [i+1,n-1].
        // left record the maxProfit for [0,i], use left[i] to get left[i+1] in O(1)
        // right record the maxProfit for [i+1,n-1], use right[i+1] to get right[i] in O(1)
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int minVal = prices[0];
        for (int i = 1 ; i < n; ++i) {
            left[i] = max(left[i-1], prices[i]-minVal);
            minVal = min(minVal, prices[i]);
        }
        int maxVal = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            right[i] = max(right[i+1], maxVal-prices[i]);
            maxVal = max(maxVal, prices[i]);
        }

        for (int i = 0; i < n; ++i)
            res = max(res, left[i]+right[i]);
        return res;
    }   
};

int main() {
    Solution sol;
    vector<int> prices = {3,4,1,2,4,5,3};
    vector<int> prices2 = {2,1,1};
    vector<int> prices3 = {1,2};
    cout << (5 == sol.maxProfit(prices)) << endl;
    cout << (0 == sol.maxProfit(prices2)) << endl;
    cout << (1 == sol.maxProfit(prices3)) << endl;
    cout << endl;
}
