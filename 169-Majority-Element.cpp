#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    auto largest = std::max_element(nums.begin(), nums.end());

    int maxValue = *largest;

    vector<int> count(maxValue + 1, 0);

    for (int i : nums)
    {
        count[i]++;
    }

    for (int i = 0; i <= maxValue; i++)
    {
        auto countLargest = std::max_element(count.begin(), count.end());
        int a = *countLargest;
        if (count[i] == a)
        {
            cout << i;
        }
    }

    return 0;
}