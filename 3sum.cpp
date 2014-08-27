/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 *   Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *   The solution set must not contain duplicate triplets.
 */ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.size() < 3) return {};
        vector<vector<int>> res;
        set<vector<int>> exists;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size()-2; ++i) {
            vector<vector<int>> lastTwoNumsIdxes = twoSum(num, 0 - num[i], i+1);
            for (auto lastTwoNumsIdx : lastTwoNumsIdxes) {
                if (i < lastTwoNumsIdx[0]) {
                    int second = num[lastTwoNumsIdx[0]];
                    int third = num[lastTwoNumsIdx[1]];
                    vector<int> tmp = {num[i], second, third};
                    if (!exists.count(tmp)) {
                        res.push_back(tmp);
                        exists.insert(tmp);
                    }
                }
            }
        }
        return res;
    }

private:    
    vector<vector<int>> twoSum(vector<int> &numbers, int target, int start) {
        vector<vector<int>> result;
        unordered_map<int, int> map; // map[number] = index;
        for (int i = 0; i < numbers.size(); ++i)
            map[numbers[i]] = i;
        for (int i = start; i < numbers.size()-1; ++i) {
            vector<int> res;
            int second = target - numbers[i];
            if (map.count(second) == 1) {
                if (i < map[second]) {
                    res.push_back(i);
                    res.push_back(map[second]);
                    result.push_back(res);
                }
            }
        }
        return result;
    }

    void printVector(vector<int> vec) {
        for (int item : vec) 
            cout << item << " ";
        cout << endl;
    }
};

void printVector(vector<int> vec) {
    for (int item : vec) 
        cout << item << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> numbers = {-2,0,1,1,2};
    vector<vector<int>> res = sol.threeSum(numbers);
    for (auto vec : res) {
        printVector(vec); 
    }
    cout << endl;
}
