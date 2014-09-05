/* 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. 
 * You may complete as many transactions as you like 
 * (ie, buy one and sell one share of the stock multiple times). 
 * However, you may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int delta = prices[i] - prices[i-1];
            if (delta > 0)
                res += delta;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,4,1,2,4,5,3};
    vector<int> prices2 = {2,1,1};
    vector<int> prices3 = {1,2};
    vector<int> prices4 = {2,1};
    cout << (5 == sol.maxProfit(prices)) << endl;
    cout << (0 == sol.maxProfit(prices2)) << endl;
    cout << (1 == sol.maxProfit(prices3)) << endl;
    cout << (0 == sol.maxProfit(prices4)) << endl;
    vector<int> prices5 = {2,1,2,0,1};
    cout << (2 == sol.maxProfit(prices5)) << endl;
    cout << endl;
}
