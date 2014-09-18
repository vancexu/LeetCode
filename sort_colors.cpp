/* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            count[A[i]]++;
        }

        for (int i = 0; i < count[0]; ++i) 
            A[i] = 0;
        for (int i = count[0]; i < count[0]+count[1]; ++i)
            A[i] = 1;
        for (int i = count[0]+count[1]; i < n; ++i)
            A[i] = 2;
    }
};

int main() {
    Solution sol;
    int A[] = {0,1,2,0,1,2};
    sol.sortColors(A, 6);
    for (int i = 0; i < 6; ++i) 
        cout << A[i] << " ";
    cout << endl;
}
