#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // ...write your code here...
        int n = s.length();
        int ans = 0;
        int l = 0;
        int r = 0;
        int arr[256] = {0};
        while (r < n)
        {
            if (arr[s[r]] == 0)
            {
                arr[s[r]]++;
                ans = max(ans, r - l + 1);
                r++;
            }
            else
            {
                arr[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};

void runTests()
{
    Solution solution;

    // Basic test cases
    assert(solution.lengthOfLongestSubstring("abcabcbb") == 3); // Expected output: 3
    assert(solution.lengthOfLongestSubstring("bbbbb") == 1);    // Expected output: 1
    assert(solution.lengthOfLongestSubstring("pwwkew") == 3);   // Expected output: 3

    // Edge cases
    assert(solution.lengthOfLongestSubstring("") == 0);    // Expected output: 0 (empty string)
    assert(solution.lengthOfLongestSubstring(" ") == 1);   // Expected output: 1 (single space)
    assert(solution.lengthOfLongestSubstring("au") == 2);  // Expected output: 2
    assert(solution.lengthOfLongestSubstring("aab") == 2); // Expected output: 2

    // Special cases
    assert(solution.lengthOfLongestSubstring("dvdf") == 3);    // Expected output: 3
    assert(solution.lengthOfLongestSubstring("anviaj") == 5);  // Expected output: 5
    assert(solution.lengthOfLongestSubstring("tmmzuxt") == 5); // Expected output: 5

    // Large input case
    string largeInput(100000, 'a');
    assert(solution.lengthOfLongestSubstring(largeInput) == 1); // Expected output: 1 (all characters are the same)

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
