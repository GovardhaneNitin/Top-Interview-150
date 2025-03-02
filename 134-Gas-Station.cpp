#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // write your solution here
        int n = gas.size();

        int totalCost = 0;
        for (int i = 0; i < n; i++)
        {
            totalCost = totalCost + cost[i];
        }

        int totalGas = 0;
        for (int i = 0; i < n; i++)
        {
            totalGas = totalGas + gas[i];
        }

        if (totalCost == totalGas)
        {
            return totalCost / n;
        }
        else if (totalCost < totalGas)
        {
            return 0;
        }

        return -1;
    }
};

void runTests()
{
    Solution sol;
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1: " << (sol.canCompleteCircuit(gas1, cost1) == 3 ? "Passed" : "Failed") << endl;

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test Case 2: " << (sol.canCompleteCircuit(gas2, cost2) == -1 ? "Passed" : "Failed") << endl;

    // Edge cases
    vector<int> gas3 = {5};
    vector<int> cost3 = {4};
    cout << "Edge Case 1: " << (sol.canCompleteCircuit(gas3, cost3) == 0 ? "Passed" : "Failed") << endl;

    vector<int> gas4 = {4};
    vector<int> cost4 = {5};
    cout << "Edge Case 2: " << (sol.canCompleteCircuit(gas4, cost4) == -1 ? "Passed" : "Failed") << endl;

    // New test case
    vector<int> gas5 = {5, 1, 2, 3, 4};
    vector<int> cost5 = {4, 4, 1, 5, 1};
    cout << "Test Case 3: " << (sol.canCompleteCircuit(gas5, cost5) == 4 ? "Passed" : "Failed") << endl;
}

int main()
{
    runTests();
    return 0;
}
