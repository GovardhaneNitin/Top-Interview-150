#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (merged.back()[1] >= intervals[i][0])
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

void runTests()
{
    Solution solution;

    // Test Case 1: Basic test case with overlapping intervals
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> expected1 = {{1, 6}, {8, 10}, {15, 18}};
    cout << "Test Case 1: " << (solution.merge(intervals1) == expected1 ? "Passed" : "Failed") << endl;

    // Test Case 2: No overlapping intervals
    vector<vector<int>> intervals2 = {{1, 2}, {3, 4}, {5, 6}};
    vector<vector<int>> expected2 = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Test Case 2: " << (solution.merge(intervals2) == expected2 ? "Passed" : "Failed") << endl;

    // Test Case 3: All intervals overlap into one
    vector<vector<int>> intervals3 = {{1, 4}, {2, 3}, {3, 5}};
    vector<vector<int>> expected3 = {{1, 5}};
    cout << "Test Case 3: " << (solution.merge(intervals3) == expected3 ? "Passed" : "Failed") << endl;

    // Test Case 4: Single interval
    vector<vector<int>> intervals4 = {{1, 5}};
    vector<vector<int>> expected4 = {{1, 5}};
    cout << "Test Case 4: " << (solution.merge(intervals4) == expected4 ? "Passed" : "Failed") << endl;

    // Test Case 5: Empty input
    vector<vector<int>> intervals5 = {};
    vector<vector<int>> expected5 = {};
    cout << "Test Case 5: " << (solution.merge(intervals5) == expected5 ? "Passed" : "Failed") << endl;

    // Test Case 6: Intervals with the same start and end points
    vector<vector<int>> intervals6 = {{1, 4}, {1, 4}, {1, 4}};
    vector<vector<int>> expected6 = {{1, 4}};
    cout << "Test Case 6: " << (solution.merge(intervals6) == expected6 ? "Passed" : "Failed") << endl;

    // Test Case 7: Large input
    vector<vector<int>> intervals7 = {{1, 1000000}, {500000, 1500000}, {2000000, 3000000}};
    vector<vector<int>> expected7 = {{1, 1500000}, {2000000, 3000000}};
    cout << "Test Case 7: " << (solution.merge(intervals7) == expected7 ? "Passed" : "Failed") << endl;

    // Test Case 8: Intervals with negative values
    vector<vector<int>> intervals8 = {{-10, -1}, {-5, 0}, {1, 3}};
    vector<vector<int>> expected8 = {{-10, 0}, {1, 3}};
    cout << "Test Case 8: " << (solution.merge(intervals8) == expected8 ? "Passed" : "Failed") << endl;
}

int main()
{
    runTests();
    return 0;
}
