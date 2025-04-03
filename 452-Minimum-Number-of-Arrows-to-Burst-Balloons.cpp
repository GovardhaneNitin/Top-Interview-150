#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int arrows = 1;
        int end = points[0][1];

        for (const auto &point : points)
        {
            if (point[0] > end)
            {
                arrows++;
                end = point[1];
            }
        }

        return arrows;
    }
};

void runTests()
{
    Solution solution;

    // Test Case 1: Basic test case with overlapping intervals
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Test Case 1: " << solution.findMinArrowShots(points1) << " (Expected: 2)" << endl;

    // Test Case 2: Non-overlapping intervals
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Test Case 2: " << solution.findMinArrowShots(points2) << " (Expected: 4)" << endl;

    // Test Case 3: Fully overlapping intervals
    vector<vector<int>> points3 = {{1, 10}, {2, 9}, {3, 8}, {4, 7}};
    cout << "Test Case 3: " << solution.findMinArrowShots(points3) << " (Expected: 1)" << endl;

    // Test Case 4: Single balloon
    vector<vector<int>> points4 = {{1, 2}};
    cout << "Test Case 4: " << solution.findMinArrowShots(points4) << " (Expected: 1)" << endl;

    // Test Case 5: Empty input
    vector<vector<int>> points5 = {};
    cout << "Test Case 5: " << solution.findMinArrowShots(points5) << " (Expected: 0)" << endl;

    // Test Case 6: Large input with many overlapping intervals
    vector<vector<int>> points6 = {{1, 100}, {2, 99}, {3, 98}, {4, 97}, {5, 96}};
    cout << "Test Case 6: " << solution.findMinArrowShots(points6) << " (Expected: 1)" << endl;

    // Test Case 7: Intervals with the same start and end points
    vector<vector<int>> points7 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    cout << "Test Case 7: " << solution.findMinArrowShots(points7) << " (Expected: 4)" << endl;

    // Test Case 8: Intervals with negative coordinates
    vector<vector<int>> points8 = {{-10, -1}, {-5, 0}, {-3, 2}, {1, 5}};
    cout << "Test Case 8: " << solution.findMinArrowShots(points8) << " (Expected: 2)" << endl;

    // Test Case 9: Intervals with repeated values
    vector<vector<int>> points9 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Test Case 9: " << solution.findMinArrowShots(points9) << " (Expected: 1)" << endl;

    // Test Case 10: Large number of balloons with no overlap
    vector<vector<int>> points10;
    for (int i = 0; i < 1000; ++i)
    {
        points10.push_back({i * 2, i * 2 + 1});
    }
    cout << "Test Case 10: " << solution.findMinArrowShots(points10) << " (Expected: 1000)" << endl;
}

int main()
{
    runTests();
    return 0;
}
