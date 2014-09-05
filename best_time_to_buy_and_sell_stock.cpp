/* Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), 
 * design an algorithm to find the maximum profit.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int minVal = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i-1]) {
                res = max(res, prices[i] - minVal);
            } else {
                minVal = min(minVal, prices[i]);
            }
        }
        return res;
    }   
};

int main() {
    Solution sol;
    vector<int> prices = {3,4,1,2,4,5,3};
    vector<int> prices2 = {2,1,1};
    vector<int> prices3 = {1,2};
    cout << (4 == sol.maxProfit(prices)) << endl;
    cout << (0 == sol.maxProfit(prices2)) << endl;
    cout << (1 == sol.maxProfit(prices3)) << endl;
    cout << endl;
}
