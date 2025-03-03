#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> rows(numRows);
        int len = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < len; ++i)
        {
            int row = i % cycleLen;
            if (row >= numRows)
                row = cycleLen - row;
            rows[row] += s[i];
        }

        string ret;
        for (string row : rows)
            ret += row;
        return ret;
    }
};

void test()
{
    Solution solution;

    // Test case 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    string expected1 = "PAHNAPLSIIGYIR";
    assert(solution.convert(s1, numRows1) == expected1);

    // Test case 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    string expected2 = "PINALSIGYAHRPI";
    assert(solution.convert(s2, numRows2) == expected2);

    // Edge case 1: Single row
    string s3 = "A";
    int numRows3 = 1;
    string expected3 = "A";
    assert(solution.convert(s3, numRows3) == expected3);

    // Edge case 2: Empty string
    string s4 = "";
    int numRows4 = 3;
    string expected4 = "";
    assert(solution.convert(s4, numRows4) == expected4);

    // Edge case 3: numRows greater than string length
    string s5 = "AB";
    int numRows5 = 3;
    string expected5 = "AB";
    assert(solution.convert(s5, numRows5) == expected5);

    cout << "All test cases passed!" << endl;
}

int main()
{
    test();
    return 0;
}
