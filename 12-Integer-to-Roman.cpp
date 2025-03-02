#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        const pair<int, string> values[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string result;
        for (const auto &pair : values)
        {
            int value = pair.first;
            const string &symbol = pair.second;
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    // Test cases
    vector<pair<int, string>> testCases = {
        {1, "I"},
        {3, "III"},
        {4, "IV"},
        {9, "IX"},
        {58, "LVIII"},
        {1994, "MCMXCIV"},
        {3999, "MMMCMXCIX"} // Edge case: largest number representable in Roman numerals
    };

    // Check if the solution matches the expected output
    for (const auto &testCase : testCases)
    {
        int num = testCase.first;
        string expected = testCase.second;
        string result = solution.intToRoman(num);
        if (result == expected)
        {
            cout << "Test case passed for input " << num << endl;
        }
        else
        {
            cout << "Test case failed for input " << num << ". Expected " << expected << " but got " << result << endl;
        }
    }

    return 0;
}
