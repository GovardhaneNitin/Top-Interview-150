#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> &nums, int n)
{
    int n = nums.size();
    int maxReach = 0; // Keeps track of the farthest index we can reach

    for (int i = 0; i < n; i++)
    {
        if (i > maxReach)
            return false; // If we can't reach this index, return false

        maxReach = max(maxReach, i + nums[i]); // Update the max reach

        if (maxReach >= n - 1)
            return true; // If we can reach the last index, return true
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 3, 2, 9, 1, 4, 6};

    int n = nums.size();

    cout << canJump(nums, n);

    return 0;
}