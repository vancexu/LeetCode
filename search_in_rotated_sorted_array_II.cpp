/* Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) return false;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) return true;
            else if (A[low] < A[mid]) {
                if (A[low] <= target && target < A[mid]) 
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if (A[low] > A[mid]) {
                if (A[mid] < target && target <= A[high])
                    low = mid + 1;
                else 
                    high = mid - 1;
            } else
                low++;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int A[] = {1,3,4,1,1,1};
    cout << (true == sol.search(A,6,3)) << endl;
    cout << endl;
}
