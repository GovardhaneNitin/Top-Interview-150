#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int> &nums, int n)
{
    int maxReach = 0;
    int currentReach = 0;
    int jump = 0;
    if (n == 1)
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxReach = max(maxReach, i + nums[i]);
        if (currentReach == i)
        {
            if (maxReach > i)
            {
                jump++;
                currentReach = maxReach;
            }
        }
    }

    return jump;
}

int main()
{
    vector<int> nums1 = {2, 3, 1, 1, 4};                       // Expected output: 2
    vector<int> nums2 = {2, 3, 0, 1, 4};                       // Expected output: 2
    vector<int> nums3 = {1, 2, 3, 4, 5};                       // Expected output: 3
    vector<int> nums4 = {1, 1, 1, 1, 1};                       // Expected output: 4
    vector<int> nums5 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}; // Expected output: 1
    vector<int> nums6 = {0};                                   // Edge case: single element, Expected output: 0
    vector<int> nums7 = {1, 2};                                // Edge case: two elements, Expected output: 1

    cout << "Test case 1: " << jump(nums1, nums1.size()) << " (Expected: 2)" << endl;
    cout << "Test case 2: " << jump(nums2, nums2.size()) << " (Expected: 2)" << endl;
    cout << "Test case 3: " << jump(nums3, nums3.size()) << " (Expected: 3)" << endl;
    cout << "Test case 4: " << jump(nums4, nums4.size()) << " (Expected: 4)" << endl;
    cout << "Test case 5: " << jump(nums5, nums5.size()) << " (Expected: 1)" << endl;
    cout << "Test case 6: " << jump(nums6, nums6.size()) << " (Expected: 0)" << endl;
    cout << "Test case 7: " << jump(nums7, nums7.size()) << " (Expected: 1)" << endl;

    return 0;
}