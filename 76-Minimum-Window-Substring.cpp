#include <iostream>
#include <string>
#include <cassert>
#include <limits>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // ...write your code here...
        if (s.empty() || t.empty())
        {
            return "";
        }

        int t_freq[128] = {0};
        int window_freq[128] = {0};

        for (char c : t)
        {
            t_freq[c]++;
        }

        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start_index = 0;
        int matched = 0;

        while (right < s.length())
        {
            char c = s[right];
            window_freq[c]++;

            if (t_freq[c] != 0 && window_freq[c] <= t_freq[c])
            {
                matched++;
            }

            while (matched == t.length())
            {
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    start_index = left;
                }

                char left_char = s[left];
                window_freq[left_char]--;

                if (t_freq[left_char] != 0 && window_freq[left_char] < t_freq[left_char])
                {
                    matched--;
                }

                left++;
            }
            right++;
        }

        if (min_len == INT_MAX)
        {
            return "";
        }

        return s.substr(start_index, min_len);
    }
};

void runTests()
{
    Solution sol;

    // Basic test cases
    assert(sol.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(sol.minWindow("a", "a") == "a");
    assert(sol.minWindow("a", "aa") == "");

    // Edge cases
    assert(sol.minWindow("", "A") == "");
    assert(sol.minWindow("A", "") == "");
    assert(sol.minWindow("a", "b") == "");
    assert(sol.minWindow(string(1000, 'a'), "a") == "a");

    // Special cases
    assert(sol.minWindow("aa", "aa") == "aa");
    assert(sol.minWindow("ab", "A") == "");
    assert(sol.minWindow("ab", "b") == "b");
    assert(sol.minWindow("ab", "a") == "a");
    assert(sol.minWindow("ab", "ab") == "ab");
    assert(sol.minWindow("abc", "cba") == "abc");

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
