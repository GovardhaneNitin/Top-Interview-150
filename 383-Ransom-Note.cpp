#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // ...write your code here...
        for (char c : ransomNote)
        {
            size_t pos = magazine.find(c);
            if (pos == string::npos)
            {
            return false;
            }
            magazine.erase(pos, 1);
        }
        return true;
    }
};

void runTests()
{
    Solution solution;

    // Test case 1: Basic test case
    cout << (solution.canConstruct("a", "b") == false) << endl; // Expected output: 1 (true)

    // Test case 2: Basic test case
    cout << (solution.canConstruct("aa", "ab") == false) << endl; // Expected output: 1 (true)

    // Test case 3: Basic test case
    cout << (solution.canConstruct("aa", "aab") == true) << endl; // Expected output: 1 (true)

    // Test case 4: Edge case with empty ransomNote
    cout << (solution.canConstruct("", "aab") == true) << endl; // Expected output: 1 (true)

    // Test case 5: Edge case with empty magazine
    cout << (solution.canConstruct("a", "") == false) << endl; // Expected output: 1 (true)

    // Test case 6: Edge case with both empty ransomNote and magazine
    cout << (solution.canConstruct("", "") == true) << endl; // Expected output: 1 (true)

    // Test case 7: Special case with repeated characters
    cout << (solution.canConstruct("aaa", "aaabbb") == true) << endl; // Expected output: 1 (true)

    // Test case 8: Special case with insufficient characters in magazine
    cout << (solution.canConstruct("aaa", "aab") == false) << endl; // Expected output: 1 (true)

    // Test case 9: Large input case
    string largeRansomNote(100000, 'a');
    string largeMagazine(100000, 'a');
    cout << (solution.canConstruct(largeRansomNote, largeMagazine) == true) << endl; // Expected output: 1 (true)

    // Test case 10: Large input case with insufficient characters
    string largeRansomNoteInsufficient(100001, 'a');
    cout << (solution.canConstruct(largeRansomNoteInsufficient, largeMagazine) == false) << endl; // Expected output: 1 (true)
}

int main()
{
    runTests();
    return 0;
}
