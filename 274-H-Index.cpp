#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // write your code here
        int n = citations.size();

        sort(citations.begin(), citations.end(), greater<int>());

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (citations[i] > i)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<int> test1 = {3, 0, 6, 1, 5}; // Expected output: 3
    vector<int> test2 = {1, 3, 1};       // Expected output: 1
    vector<int> test3 = {0};             // Expected output: 0

    cout << "Test Case 1: " << solution.hIndex(test1) << endl;
    cout << "Test Case 2: " << solution.hIndex(test2) << endl;
    cout << "Test Case 3: " << solution.hIndex(test3) << endl;

    return 0;
}