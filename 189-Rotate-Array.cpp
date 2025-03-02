#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nums[] = {1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    int n = sizeof(nums) / sizeof(nums[0]);

    reverseArray(nums, 0, n - k - 1);
    reverseArray(nums, n - k, n - 1);
    reverseArray(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}