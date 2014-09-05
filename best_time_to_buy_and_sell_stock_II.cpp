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
        int profit = maxProfitOnce(prices);
        while (profit != 0) {
            res += profit;
            profit = maxProfitOnce(prices);
        }
        return res;
    }

    int maxProfitOnce(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int minVal = prices[0];
        int res = 0;
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i-1]) {
                if (prices[i] - minVal >= res) {
                    res = prices[i] - minVal;
                    maxIndex = i;
                }
            } else {
                if (minVal > prices[i]) {
                    minVal = prices[i];
                    minIndex = i;
                }
            }
        }
        if (minIndex < maxIndex) {
            prices.erase(prices.begin()+maxIndex);
            prices.erase(prices.begin()+minIndex);
        } else if (minIndex > maxIndex) {
            prices.erase(prices.begin()+minIndex);
            prices.erase(prices.begin()+maxIndex);
        } else {
            prices.erase(prices.begin()+maxIndex);
        } 
        return res;
    }   
};

int main() {
    Solution sol;
    /*
    vector<int> prices = {3,4,1,2,4,5,3};
    vector<int> prices2 = {2,1,1};
    vector<int> prices3 = {1,2};
    vector<int> prices4 = {2,1};
    cout << (7 == sol.maxProfit(prices)) << endl;
    cout << (0 == sol.maxProfit(prices2)) << endl;
    cout << (1 == sol.maxProfit(prices3)) << endl;
    cout << (0 == sol.maxProfit(prices4)) << endl;
    */
    vector<int> prices = {2,1,2,0,1};
    cout << sol.maxProfit(prices) << endl;
    cout << endl;
}
