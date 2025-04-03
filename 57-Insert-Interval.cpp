#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // ...write your code here...
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (const auto &interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

void runTestCases()
{
    Solution solution;

    // Test Case 1: Basic case with no overlap
    vector<vector<int>> intervals1 = {{1, 2}, {3, 5}, {6, 7}};
    vector<int> newInterval1 = {8, 10};
    vector<vector<int>> expected1 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
    cout << "Test Case 1: " << (solution.insert(intervals1, newInterval1) == expected1 ? "Passed" : "Failed") << endl;

    // Test Case 2: Overlapping intervals
    vector<vector<int>> intervals2 = {{1, 3}, {6, 9}};
    vector<int> newInterval2 = {2, 5};
    vector<vector<int>> expected2 = {{1, 5}, {6, 9}};
    cout << "Test Case 2: " << (solution.insert(intervals2, newInterval2) == expected2 ? "Passed" : "Failed") << endl;

    // Test Case 3: New interval merges all existing intervals
    vector<vector<int>> intervals3 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval3 = {4, 13};
    vector<vector<int>> expected3 = {{1, 2}, {3, 16}};
    cout << "Test Case 3: " << (solution.insert(intervals3, newInterval3) == expected3 ? "Passed" : "Failed") << endl;

    // Test Case 4: Empty intervals
    vector<vector<int>> intervals4 = {};
    vector<int> newInterval4 = {5, 7};
    vector<vector<int>> expected4 = {{5, 7}};
    cout << "Test Case 4: " << (solution.insert(intervals4, newInterval4) == expected4 ? "Passed" : "Failed") << endl;

    // Test Case 5: New interval is before all existing intervals
    vector<vector<int>> intervals5 = {{3, 5}, {6, 7}};
    vector<int> newInterval5 = {1, 2};
    vector<vector<int>> expected5 = {{1, 2}, {3, 5}, {6, 7}};
    cout << "Test Case 5: " << (solution.insert(intervals5, newInterval5) == expected5 ? "Passed" : "Failed") << endl;

    // Test Case 6: New interval is after all existing intervals
    vector<vector<int>> intervals6 = {{1, 2}, {3, 5}};
    vector<int> newInterval6 = {6, 7};
    vector<vector<int>> expected6 = {{1, 2}, {3, 5}, {6, 7}};
    cout << "Test Case 6: " << (solution.insert(intervals6, newInterval6) == expected6 ? "Passed" : "Failed") << endl;

    // Test Case 7: New interval overlaps partially with one interval
    vector<vector<int>> intervals7 = {{1, 3}, {6, 9}};
    vector<int> newInterval7 = {2, 6};
    vector<vector<int>> expected7 = {{1, 9}};
    cout << "Test Case 7: " << (solution.insert(intervals7, newInterval7) == expected7 ? "Passed" : "Failed") << endl;

    // Test Case 8: Single interval in the list
    vector<vector<int>> intervals8 = {{1, 5}};
    vector<int> newInterval8 = {2, 3};
    vector<vector<int>> expected8 = {{1, 5}};
    cout << "Test Case 8: " << (solution.insert(intervals8, newInterval8) == expected8 ? "Passed" : "Failed") << endl;

    // Test Case 9: New interval is identical to an existing interval
    vector<vector<int>> intervals9 = {{1, 3}, {6, 9}};
    vector<int> newInterval9 = {6, 9};
    vector<vector<int>> expected9 = {{1, 3}, {6, 9}};
    cout << "Test Case 9: " << (solution.insert(intervals9, newInterval9) == expected9 ? "Passed" : "Failed") << endl;

    // Test Case 10: Large input
    vector<vector<int>> intervals10 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    vector<int> newInterval10 = {2, 9};
    vector<vector<int>> expected10 = {{1, 10}};
    cout << "Test Case 10: " << (solution.insert(intervals10, newInterval10) == expected10 ? "Passed" : "Failed") << endl;
}

int main()
{
    runTestCases();
    return 0;
}
