#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // write your code here
        int n = ratings.size();

        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += candies[i];
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Test case 1: " << solution.candy(ratings1) << " (Expected: 5)" << endl;

    // Test case 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Test case 2: " << solution.candy(ratings2) << " (Expected: 4)" << endl;

    // Edge case 1: Single child
    vector<int> ratings3 = {1};
    cout << "Edge case 1: " << solution.candy(ratings3) << " (Expected: 1)" << endl;

    // Edge case 2: All children with the same rating
    vector<int> ratings4 = {2, 2, 2, 2};
    cout << "Edge case 2: " << solution.candy(ratings4) << " (Expected: 4)" << endl;

    // Edge case 3: Decreasing ratings
    vector<int> ratings5 = {5, 4, 3, 2, 1};
    cout << "Edge case 3: " << solution.candy(ratings5) << " (Expected: 15)" << endl;

    return 0;
}
