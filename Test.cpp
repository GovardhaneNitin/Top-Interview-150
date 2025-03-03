#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s = "hello world";

    int n = s.size();

    vector<string> arr(n, s);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}