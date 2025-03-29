#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // write your code here
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test Case 1: Basic test case with nearby duplicates
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << "Test Case 1: " << solution.containsNearbyDuplicate(nums1, k1) << " (Expected: 1)" << endl;

    // Test Case 2: No nearby duplicates
    vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Test Case 2: " << solution.containsNearbyDuplicate(nums2, k2) << " (Expected: 0)" << endl;

    // Test Case 3: Duplicate exists but not within range k
    vector<int> nums3 = {1, 0, 1, 1};
    int k3 = 1;
    cout << "Test Case 3: " << solution.containsNearbyDuplicate(nums3, k3) << " (Expected: 1)" << endl;

    // Test Case 4: Empty input
    vector<int> nums4 = {};
    int k4 = 0;
    cout << "Test Case 4: " << solution.containsNearbyDuplicate(nums4, k4) << " (Expected: 0)" << endl;

    // Test Case 5: Single element
    vector<int> nums5 = {1};
    int k5 = 1;
    cout << "Test Case 5: " << solution.containsNearbyDuplicate(nums5, k5) << " (Expected: 0)" << endl;

    // Test Case 6: Large input with no duplicates
    vector<int> nums6(10000, 0);
    for (int i = 0; i < 10000; ++i)
        nums6[i] = i;
    int k6 = 5000;
    cout << "Test Case 6: " << solution.containsNearbyDuplicate(nums6, k6) << " (Expected: 0)" << endl;

    // Test Case 7: Large input with duplicates within range
    vector<int> nums7(10000, 0);
    for (int i = 0; i < 10000; ++i)
        nums7[i] = i % 100;
    int k7 = 50;
    cout << "Test Case 7: " << solution.containsNearbyDuplicate(nums7, k7) << " (Expected: 1)" << endl;

    // Test Case 8: Negative numbers with duplicates
    vector<int> nums8 = {-1, -2, -3, -1};
    int k8 = 3;
    cout << "Test Case 8: " << solution.containsNearbyDuplicate(nums8, k8) << " (Expected: 1)" << endl;

    // Test Case 9: All elements are the same
    vector<int> nums9 = {1, 1, 1, 1};
    int k9 = 1;
    cout << "Test Case 9: " << solution.containsNearbyDuplicate(nums9, k9) << " (Expected: 1)" << endl;

    // Test Case 10: k is zero
    vector<int> nums10 = {1, 2, 3, 1};
    int k10 = 0;
    cout << "Test Case 10: " << solution.containsNearbyDuplicate(nums10, k10) << " (Expected: 0)" << endl;

    return 0;
}
