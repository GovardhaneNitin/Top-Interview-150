#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // Write your code here
        unordered_map<char, int> roman = {
            {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};

        int n = s.size();

        int total = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]])
            {
                total -= roman[s[i]];
            }
            else
            {
                total += roman[s[i]];
            }
        }

        return total;
    }
};

int main()
{
    Solution solution;

    // Test cases
    bool allPassed = true;
    allPassed &= (solution.romanToInt("III") == 3);
    allPassed &= (solution.romanToInt("IV") == 4);
    allPassed &= (solution.romanToInt("IX") == 9);
    allPassed &= (solution.romanToInt("LVIII") == 58);
    allPassed &= (solution.romanToInt("MCMXCIV") == 1994);

    // Edge cases
    allPassed &= (solution.romanToInt("I") == 1);
    allPassed &= (solution.romanToInt("MMMCMXCIX") == 3999);
    allPassed &= (solution.romanToInt("CDXLIV") == 444);

    if (allPassed)
    {
        cout << "All test cases pass" << endl;
    }
    else
    {
        cout << "Some test cases failed" << endl;
    }

    return 0;
}
