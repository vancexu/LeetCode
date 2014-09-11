/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& num) {
        // from right to left, find the first item (index i) that break the increasing order
        // then from right to left, find the first item (index j) bigger than num[i]
        // swap num[i] and num[j], then reverse num[i+1, end)
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i-1]) {
            i--;
        }
        if (i == 0) {
            reverse(num.begin(), num.end());
        } else {
            i--;
            int j = num.size() - 1;
            while (num[j] <= num[i]) j--;
            swap(num[i], num[j]);
            reverse(num.begin()+i+1, num.end());
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,1,4,3,2};
    sol.nextPermutation(nums);
    for (int item : nums) 
        cout << item << " ";
    cout << endl;
}
