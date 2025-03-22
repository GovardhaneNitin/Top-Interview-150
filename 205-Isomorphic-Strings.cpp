#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // ...write your code here...
        if (s.length() != t.length())
            return false;

        int map_s[256] = {0};
        int map_t[256] = {0};

        for (int i = 0; i < s.length(); ++i)
        {
            if (map_s[s[i]] != map_t[t[i]])
                return false;

            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }

        return true;
    }
};

int main()
{
    Solution solution;

    // Basic test cases
    assert(solution.isIsomorphic("egg", "add") == true);     // Expected output: true
    assert(solution.isIsomorphic("foo", "bar") == false);    // Expected output: false
    assert(solution.isIsomorphic("paper", "title") == true); // Expected output: true

    // Edge cases
    assert(solution.isIsomorphic("", "") == true);      // Expected output: true (both strings are empty)
    assert(solution.isIsomorphic("a", "a") == true);    // Expected output: true (single character, same)
    assert(solution.isIsomorphic("a", "b") == false);   // Expected output: false (single character, different)
    assert(solution.isIsomorphic("ab", "aa") == false); // Expected output: false (different mapping)

    // Special cases
    assert(solution.isIsomorphic("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba") == true); // Expected output: true (all characters mapped uniquely)
    assert(solution.isIsomorphic("aaaa", "bbbb") == true);                                             // Expected output: true (repeated characters, same pattern)
    assert(solution.isIsomorphic("abab", "baba") == true);                                             // Expected output: true (repeated pattern)

    cout << "All test cases passed!" << endl;
    return 0;
}
