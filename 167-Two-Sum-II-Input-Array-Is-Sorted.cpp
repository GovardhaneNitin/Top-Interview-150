#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // ...write your code here...
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
            return {left + 1, right + 1};
            }
            else if (sum < target)
            {
            ++left;
            }
            else
            {
            --right;
            }
        }
        return {};
    }
};

void runTest(vector<int> numbers, int target, vector<int> expected)
{
    Solution sol;
    vector<int> result = sol.twoSum(numbers, target);
    if (result == expected)
    {
        cout << "Test passed!" << endl;
    }
    else
    {
        cout << "Test failed!" << endl;
        cout << "Expected: ";
        for (int num : expected)
            cout << num << " ";
        cout << "\nGot: ";
        for (int num : result)
            cout << num << " ";
        cout << endl;
    }
}

int main()
{
    // Test case 1: Normal case
    runTest({2, 7, 11, 15}, 9, {1, 2});

    // Test case 2: Another normal case
    runTest({2, 3, 4}, 6, {1, 3});

    // Test case 3: Edge case with negative numbers
    runTest({-1, 0}, -1, {1, 2});

    // Test case 4: Edge case with larger numbers
    runTest({1, 2, 3, 4, 4, 9, 56, 90}, 8, {4, 5});

    // Test case 5: Edge case with no solution
    runTest({1, 2, 3, 4, 5}, 10, {});

    return 0;
}
