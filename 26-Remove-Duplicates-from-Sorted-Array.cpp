#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int size)
{
    int k = 0;
    for (int i = 1; i < size; i++)
    {
        if (nums[i] != nums[k])
        {
            k++;
            nums[k] = nums[i];
        }
    }

    return k + 1;
}

int main()
{
    int nums[] = {1, 1, 2};

    int size = sizeof(nums) / sizeof(nums[0]);

    cout << removeDuplicates(nums, size);

    // int k = 0;

    // for (int i = 1; i < size; i++)
    // {
    //     if (nums[i] != nums[k])
    //     {
    //         k++;
    //         nums[k] = nums[i];
    //     }
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << nums[i];
    // }

    return 0;
}