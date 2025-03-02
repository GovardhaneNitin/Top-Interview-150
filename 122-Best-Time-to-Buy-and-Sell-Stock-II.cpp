#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += (prices[i] - prices[i - 1]);
        }
        else
        {
            return 0;
        }
    }

    cout << profit << endl;

    return 0;
}