#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

void runTests()
{
    Solution solution;

    // Test Case 1: Basic test case with a consecutive sequence
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 1: " << solution.longestConsecutive(nums1) << " (Expected: 4)" << endl;

    // Test Case 2: Single element
    vector<int> nums2 = {1};
    cout << "Test Case 2: " << solution.longestConsecutive(nums2) << " (Expected: 1)" << endl;

    // Test Case 3: Empty input
    vector<int> nums3 = {};
    cout << "Test Case 3: " << solution.longestConsecutive(nums3) << " (Expected: 0)" << endl;

    // Test Case 4: All elements are the same
    vector<int> nums4 = {2, 2, 2, 2};
    cout << "Test Case 4: " << solution.longestConsecutive(nums4) << " (Expected: 1)" << endl;

    // Test Case 5: Large consecutive sequence
    vector<int> nums5 = {10, 11, 12, 13, 14, 15};
    cout << "Test Case 5: " << solution.longestConsecutive(nums5) << " (Expected: 6)" << endl;

    // Test Case 6: Unordered input with duplicates
    vector<int> nums6 = {1, 2, 0, 1};
    cout << "Test Case 6: " << solution.longestConsecutive(nums6) << " (Expected: 3)" << endl;

    // Test Case 7: Negative numbers
    vector<int> nums7 = {-1, -2, -3, -4};
    cout << "Test Case 7: " << solution.longestConsecutive(nums7) << " (Expected: 4)" << endl;

    // Test Case 8: Mixed positive and negative numbers
    vector<int> nums8 = {-1, 0, 1, 2, -2};
    cout << "Test Case 8: " << solution.longestConsecutive(nums8) << " (Expected: 5)" << endl;

    // Test Case 9: Large input size
    vector<int> nums9(100000, 1); // All elements are the same
    cout << "Test Case 9: " << solution.longestConsecutive(nums9) << " (Expected: 1)" << endl;
}

int main()
{
    runTests();
    return 0;
}
