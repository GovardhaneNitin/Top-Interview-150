#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    int buyPrice = INT_MAX;

    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (buyPrice < prices[i])
        {
            int profit = prices[i] - buyPrice;

            maxProfit = max(maxProfit, profit);
        }
        else
        {
            buyPrice = prices[i];
        }
    }

    cout << maxProfit;

    return 0;
}