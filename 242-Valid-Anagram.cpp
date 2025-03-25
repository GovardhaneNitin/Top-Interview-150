#include <iostream>
#include <cassert>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    // Basic test cases
    assert(solution.isAnagram("anagram", "nagaram") == true); // Expected: true
    assert(solution.isAnagram("rat", "car") == false);        // Expected: false

    // Edge cases
    assert(solution.isAnagram("", "") == true);         // Both strings empty, Expected: true
    assert(solution.isAnagram("a", "a") == true);       // Single character, same, Expected: true
    assert(solution.isAnagram("a", "b") == false);      // Single character, different, Expected: false
    assert(solution.isAnagram("abc", "abcd") == false); // Different lengths, Expected: false

    // Special cases
    assert(solution.isAnagram("aabbcc", "abcabc") == true); // Repeated characters, Expected: true
    assert(solution.isAnagram("aabbcc", "aabbc") == false); // Missing one character, Expected: false
    assert(solution.isAnagram("abc", "cba") == true);       // Same characters, different order, Expected: true
    assert(solution.isAnagram("abc", "def") == false);      // Completely different characters, Expected: false

    // Large input case
    string s1(100000, 'a'), s2(100000, 'a');
    assert(solution.isAnagram(s1, s2) == true); // Large identical strings, Expected: true
    s2[99999] = 'b';
    assert(solution.isAnagram(s1, s2) == false); // Large strings, one character different, Expected: false

    cout << "All test cases passed!" << endl;
    return 0;
}
