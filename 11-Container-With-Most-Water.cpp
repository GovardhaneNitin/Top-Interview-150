#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int width = right - left;
            int h = min(height[left], height[right]);
            max_area = max(max_area, width * h);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};

void runTestCases()
{
    Solution solution;
    vector<int> heights;
    int expected, result;

    // Test Case 1
    heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    expected = 49;
    result = solution.maxArea(heights);
    cout << "Test Case 1 - Expected: " << expected << ", Got: " << result << endl;

    // Test Case 2
    heights = {1, 1};
    expected = 1;
    result = solution.maxArea(heights);
    cout << "Test Case 2 - Expected: " << expected << ", Got: " << result << endl;

    // Test Case 3
    heights = {4, 3, 2, 1, 4};
    expected = 16;
    result = solution.maxArea(heights);
    cout << "Test Case 3 - Expected: " << expected << ", Got: " << result << endl;

    // Test Case 4
    heights = {1, 2, 1};
    expected = 2;
    result = solution.maxArea(heights);
    cout << "Test Case 4 - Expected: " << expected << ", Got: " << result << endl;

    // Edge Case 1: Empty vector
    heights = {};
    expected = 0;
    result = solution.maxArea(heights);
    cout << "Edge Case 1 - Expected: " << expected << ", Got: " << result << endl;

    // Edge Case 2: Single element
    heights = {5};
    expected = 0;
    result = solution.maxArea(heights);
    cout << "Edge Case 2 - Expected: " << expected << ", Got: " << result << endl;
}

int main()
{
    runTestCases();
    return 0;
}
