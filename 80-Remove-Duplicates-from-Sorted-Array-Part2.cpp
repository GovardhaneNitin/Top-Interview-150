#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int size)
{
    int k = 0;

    // if(nums[k]==k) {
    //     return 1;
    // }

    // for (int i = 1; i < size; i++)
    // {
    //     if (nums[k] != nums[i])
    //     {
    //         k = k + 2;
    //         nums[k] = nums[i];
    //         k = k - 1;
    //     }
    // }

    // if (nums[k] == 1 || nums[k] == k)
    // {
    //     return k + 1;
    // }

    // return k + 2;

    for (int i = 0; i < size; i++)
    {
        if (k < 2 || nums[i] != nums[k - 2])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    int nums[] = {1, 1};

    int size = sizeof(nums) / sizeof(nums[0]);

    cout << removeDuplicates(nums, size);

    return 0;
}