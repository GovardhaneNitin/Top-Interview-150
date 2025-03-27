#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // ...write your code here...
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        throw invalid_argument("No two sum solution");
    }
};

void runTestCases()
{
    Solution solution;

    // Test Case 1: Basic test case
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: Expected Output: [0, 1], Actual Output: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test Case 2: Negative numbers
    vector<int> nums2 = {-3, 4, 3, 90};
    int target2 = 0;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test Case 2: Expected Output: [0, 2], Actual Output: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test Case 3: Multiple pairs possible
    vector<int> nums3 = {1, 3, 3, 6};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test Case 3: Expected Output: [1, 2], Actual Output: [" << result3[0] << ", " << result3[1] << "]" << endl;

    // Test Case 4: Large input
    vector<int> nums4 = {1000000, 500000, -1500000};
    int target4 = -1000000;
    vector<int> result4 = solution.twoSum(nums4, target4);
    cout << "Test Case 4: Expected Output: [1, 2], Actual Output: [" << result4[0] << ", " << result4[1] << "]" << endl;

    // Test Case 5: Single element (edge case)
    vector<int> nums5 = {5};
    int target5 = 5;
    try
    {
        vector<int> result5 = solution.twoSum(nums5, target5);
        cout << "Test Case 5: Expected Output: Exception, Actual Output: [" << result5[0] << ", " << result5[1] << "]" << endl;
    }
    catch (...)
    {
        cout << "Test Case 5: Expected Output: Exception, Actual Output: Exception" << endl;
    }

    // Test Case 6: Empty input (edge case)
    vector<int> nums6 = {};
    int target6 = 0;
    try
    {
        vector<int> result6 = solution.twoSum(nums6, target6);
        cout << "Test Case 6: Expected Output: Exception, Actual Output: [" << result6[0] << ", " << result6[1] << "]" << endl;
    }
    catch (...)
    {
        cout << "Test Case 6: Expected Output: Exception, Actual Output: Exception" << endl;
    }

    // Test Case 7: Repeated values
    vector<int> nums7 = {3, 3, 4, 5};
    int target7 = 6;
    vector<int> result7 = solution.twoSum(nums7, target7);
    cout << "Test Case 7: Expected Output: [0, 1], Actual Output: [" << result7[0] << ", " << result7[1] << "]" << endl;
}

int main()
{
    runTestCases();
    return 0;
}
