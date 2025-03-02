#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // write your code here
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test case 1: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl; // Expected output: 24 12 8 6

    vector<int> nums2 = {5, 6, 7, 8};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test case 2: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl; // Expected output: 336 280 240 210

    vector<int> nums3 = {-1, 1, 0, -3, 3};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test case 3: ";
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl; // Expected output: 0 0 9 0 0

    // Edge case: Single element
    vector<int> nums4 = {1};
    vector<int> result4 = solution.productExceptSelf(nums4);
    cout << "Edge case 1: ";
    for (int num : result4)
    {
        cout << num << " ";
    }
    cout << endl; // Expected output: 1

    // Edge case: Two elements
    vector<int> nums5 = {1, 2};
    vector<int> result5 = solution.productExceptSelf(nums5);
    cout << "Edge case 2: ";
    for (int num : result5)
    {
        cout << num << " ";
    }
    cout << endl; // Expected output: 2 1

    return 0;
}
