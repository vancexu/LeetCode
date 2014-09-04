/* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /* 
     * Complexity: O(n^2)
     * for each point, compute all slop with all other points, 
     * and using unordered_map to store the number of points with the same slop
     * NOTE: 
     *      slop is int type here
     *      there are overlap points in given array
     */
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;

        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            Point p1 = points[i];
            int numOnVerticalLine = 0;
            int numOnSlop = 0;
            int repeatPoints = 1;
            unordered_map<int,int> mapSlop; // map<slop, numberOfPoints>
            for (int j = 0; j < points.size(); ++j) {
                Point p2 = points[j];
                if (i == j) continue;
                if (p1.x == p2.x && p1.y == p2.y)
                    repeatPoints++;
                else if (p1.x == p2.x) 
                    numOnVerticalLine++;
                else {
                    // note: scale slope to avoid fraction
                    int slop = 1e6 * (p1.y - p2.y) / (p1.x - p2.x);
                    mapSlop[slop]++;
                    numOnSlop = max(numOnSlop, mapSlop[slop]);
                }
            }
            result = max(result, max(numOnVerticalLine, numOnSlop)+repeatPoints);
        }
        return result;
    }

    bool samePoints(const Point& p1, const Point& p2) {
        return (p1.x == p2.x) && (p1.y == p2.y);
    }
};

int main() {
    Solution sol;
    /*
    Point p1(1,1);
    Point p2(2,2);
    Point p3(3,3);
    Point p4(3,1);
    Point p5(3,2);
    Point p6(3,4);
    */
    Point p1(3,10);
    Point p2(0,2);
    Point p3(0,2);
    Point p4(3,10);
    //vector<Point> points = {p1,p2,p3,p4,p5,p6};
    vector<Point> points = {p1,p2,p3,p4};
    cout << sol.maxPoints(points);

    cout << endl;
}
