/* Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> prev(1, 1);
        vector<int> current(2, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                current[j] = prev[j-1] + prev[j];
            }
            prev.swap(current);
            vector<int> next(i+2, 1);
            current.swap(next);
        }
        return prev;
    }
};

int main() {
    Solution sol;
    vector<int> res = sol.getRow(3);
    for (int i : res) cout << i << " ";
    cout << endl;
}
