#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, sum = 0, minLength = INT_MAX;
        for (int right = 0; right < n; ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int target;

    // Test case 1: General case
    nums = {2, 3, 1, 2, 4, 3};
    target = 7;
    cout << "Test case 1: " << solution.minSubArrayLen(target, nums) << " (Expected: 2)" << endl;

    // Test case 2: No subarray meets the target
    nums = {1, 1, 1, 1, 1, 1, 1, 1};
    target = 11;
    cout << "Test case 2: " << solution.minSubArrayLen(target, nums) << " (Expected: 0)" << endl;

    // Test case 3: Single element meets the target
    nums = {1, 2, 3, 4, 5};
    target = 4;
    cout << "Test case 3: " << solution.minSubArrayLen(target, nums) << " (Expected: 1)" << endl;

    // Test case 4: All elements sum to less than target
    nums = {1, 2, 3};
    target = 7;
    cout << "Test case 4: " << solution.minSubArrayLen(target, nums) << " (Expected: 0)" << endl;

    // Test case 5: Large numbers
    nums = {100000, 200000, 300000};
    target = 500000;
    cout << "Test case 5: " << solution.minSubArrayLen(target, nums) << " (Expected: 2)" << endl;

    return 0;
}
