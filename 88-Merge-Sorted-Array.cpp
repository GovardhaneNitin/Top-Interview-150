#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m = 3;
    int n = 3;
    int num1[] = {1, 2, 3};
    int num2[] = {4, 5, 6};

    int mergerd[m + n];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m || j < n)
    {
        if (num1[i] < num2[j])
        {
            mergerd[k] = num1[i];
            i++;
        }
        else
        {
            mergerd[k] = num2[j];
            j++;
        }
        k++;
    }

    // while (i < m)
    // {
    //     mergerd[k++] = num1[i++];
    // }

    // while (j < n)
    // {
    //     mergerd[k++] = num2[j++];
    // }

    for (int i = 0; i < k; i++)
    {
        cout << mergerd[i] << " ";
    }
    return 0;
}