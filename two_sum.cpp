/* Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, int> map; // map[number] = index;
        for (int i = 0; i < numbers.size(); ++i)
            map[numbers[i]] = i;
        for (int i = 0; i < numbers.size()-1; ++i) {
            int second = target - numbers[i];
            if (map.count(second) == 1) {
                if (map[second] != i) {
                    res.push_back(i+1);
                    res.push_back(map[second]+1);
                    return res;
                }
            }
        }
        return {};
    }
};

void printVector(vector<int> vec) {
    for (int item : vec) 
        cout << item << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> numbers = {3,2,4};
    vector<int> res = sol.twoSum(numbers, 6);
    printVector(res);
    cout << endl;
}
