#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        // ...write your code here...
        vector<string> result;
        if (nums.empty())
            return result;

        int start = nums[0];
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1)
            {
                if (start == nums[i - 1])
                    result.push_back(to_string(start));
                else
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                if (i < nums.size())
                    start = nums[i];
            }
        }
        return result;
    }
};

void runTests()
{
    Solution solution;

    // Test Case 1: Basic case with consecutive ranges
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> expected1 = {"0->2", "4->5", "7"};
    cout << "Test Case 1: " << (solution.summaryRanges(nums1) == expected1 ? "Passed" : "Failed") << endl;

    // Test Case 2: Single element
    vector<int> nums2 = {1};
    vector<string> expected2 = {"1"};
    cout << "Test Case 2: " << (solution.summaryRanges(nums2) == expected2 ? "Passed" : "Failed") << endl;

    // Test Case 3: Empty input
    vector<int> nums3 = {};
    vector<string> expected3 = {};
    cout << "Test Case 3: " << (solution.summaryRanges(nums3) == expected3 ? "Passed" : "Failed") << endl;

    // Test Case 4: No consecutive ranges
    vector<int> nums4 = {0, 2, 4, 6, 8};
    vector<string> expected4 = {"0", "2", "4", "6", "8"};
    cout << "Test Case 4: " << (solution.summaryRanges(nums4) == expected4 ? "Passed" : "Failed") << endl;

    // Test Case 5: Large input with consecutive ranges
    vector<int> nums5 = {-1000000, -999999, -999998, 1000000};
    vector<string> expected5 = {"-1000000->-999998", "1000000"};
    cout << "Test Case 5: " << (solution.summaryRanges(nums5) == expected5 ? "Passed" : "Failed") << endl;

    // Test Case 6: Negative numbers
    vector<int> nums6 = {-3, -2, -1, 1, 2, 3};
    vector<string> expected6 = {"-3->-1", "1->3"};
    cout << "Test Case 6: " << (solution.summaryRanges(nums6) == expected6 ? "Passed" : "Failed") << endl;

    // Test Case 7: Repeated values (should be treated as separate ranges)
    vector<int> nums7 = {1, 1, 2, 2, 3, 3};
    vector<string> expected7 = {"1", "1->2", "2->3", "3"};
    cout << "Test Case 7: " << (solution.summaryRanges(nums7) == expected7 ? "Passed" : "Failed") << endl;
}

int main()
{
    runTests();
    return 0;
}
