#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // ...write you code here...
        int n = height.size();

        // Calculate the Left Max Boundry - Array
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int trappedWater = 0;
        for (int i = 0; i < n; i++)
        {
            int waterLevel = min(leftMax[i], rightMax[i]);
            trappedWater += waterLevel - height[i];
        }

        return trappedWater;
    }
};

void runTests()
{
    Solution solution;

    vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << solution.trap(test1) << " (Expected: 6)" << endl;

    vector<int> test2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << solution.trap(test2) << " (Expected: 9)" << endl;

    vector<int> test3 = {1, 0, 2};
    cout << "Test 3: " << solution.trap(test3) << " (Expected: 1)" << endl;

    vector<int> test4 = {2, 0, 2};
    cout << "Test 4: " << solution.trap(test4) << " (Expected: 2)" << endl;

    vector<int> test5 = {3, 0, 0, 2, 0, 4};
    cout << "Test 5: " << solution.trap(test5) << " (Expected: 10)" << endl;

    vector<int> test6 = {};
    cout << "Test 6: " << solution.trap(test6) << " (Expected: 0)" << endl;

    vector<int> test7 = {1};
    cout << "Test 7: " << solution.trap(test7) << " (Expected: 0)" << endl;

    vector<int> test8 = {1, 2, 1};
    cout << "Test 8: " << solution.trap(test8) << " (Expected: 0)" << endl;
}

int main()
{
    runTests();
    return 0;
}
