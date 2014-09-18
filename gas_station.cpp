/* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // if sum(gas) > sum(cost), there exists a start index, else return -1.
    // Complexity: O(n)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0; 
        int current_gas = 0;
        int last_fail_index = -1;
        
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                current_gas = 0;
                last_fail_index = i;
            }
        }
        
        return total_gas < 0 ? -1 : last_fail_index + 1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {10, 5, 5, 10};
    vector<int> cost = {5, 10, 10, 5};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    cout << endl;
}
