#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
            ++j;
            }
            if (j == m) return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    // Test cases
    assert(solution.strStr("hello", "ll") == 2);
    assert(solution.strStr("aaaaa", "bba") == -1);
    assert(solution.strStr("", "") == 0);
    assert(solution.strStr("a", "") == 0);
    assert(solution.strStr("", "a") == -1);
    assert(solution.strStr("mississippi", "issip") == 4);
    assert(solution.strStr("mississippi", "pi") == 9);

    cout << "All test cases passed!" << endl;

    return 0;
}
