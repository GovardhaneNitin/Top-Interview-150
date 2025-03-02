#include <iostream>
using namespace std;

int removeElement(int nums[], int size, int val)
{
    int extraSpaceSize = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] != val)
        {
            nums[extraSpaceSize] = nums[i];
            extraSpaceSize++;
        }
    }

    return extraSpaceSize;
}

int main()
{
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    int newSize = removeElement(nums, size, val);

    for (int i = 0; i < newSize; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}