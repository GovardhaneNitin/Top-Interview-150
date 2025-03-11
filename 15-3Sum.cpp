#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // ...write your code here...
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
                else if (sum < 0)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
        return result;
    }
};

void runTestCases()
{
    Solution solution;
    vector<int> nums;
    vector<vector<int>> result;

    // Test case 1: General case
    nums = {-1, 0, 1, 2, -1, -4};
    result = solution.threeSum(nums);
    cout << "Test case 1: Expected output: [[-1, -1, 2], [-1, 0, 1]]" << endl;

    // Test case 2: No triplets
    nums = {1, 2, -2, -1};
    result = solution.threeSum(nums);
    cout << "Test case 2: Expected output: []" << endl;

    // Test case 3: All zeros
    nums = {0, 0, 0, 0};
    result = solution.threeSum(nums);
    cout << "Test case 3: Expected output: [[0, 0, 0]]" << endl;

    // Test case 4: Less than three numbers
    nums = {1, 2};
    result = solution.threeSum(nums);
    cout << "Test case 4: Expected output: []" << endl;

    // Test case 5: Large numbers
    nums = {-1000000, 500000, 500000};
    result = solution.threeSum(nums);
    cout << "Test case 5: Expected output: [[-1000000, 500000, 500000]]" << endl;
}

int main()
{
    runTestCases();
    return 0;
}
