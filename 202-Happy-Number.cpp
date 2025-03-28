#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n <= 0)
            return false;

        auto getNext = [](int num)
        {
            int sum = 0;
            while (num > 0)
            {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            return sum;
        };

        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<int> testCases = {
        19,     // Basic case: Happy number
        2,      // Basic case: Not a happy number
        1,      // Edge case: Smallest happy number
        0,      // Edge case: Invalid input (not positive)
        -7,     // Edge case: Negative number (invalid input)
        100,    // Special case: Happy number with multiple digits
        999999, // Large input: Not a happy number
        7,      // Special case: Single-digit happy number
        4       // Special case: Single-digit not a happy number
    };

    // Expected outputs
    vector<bool> expectedOutputs = {
        true,  // 19 is a happy number
        false, // 2 is not a happy number
        true,  // 1 is a happy number
        false, // 0 is invalid
        false, // Negative numbers are invalid
        true,  // 100 is a happy number
        false, // 999999 is not a happy number
        true,  // 7 is a happy number
        false  // 4 is not a happy number
    };

    // Run test cases
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        int input = testCases[i];
        bool result = solution.isHappy(input);
        cout << "Test case " << i + 1 << ": Input = " << input
             << ", Output = " << result
             << ", Expected = " << expectedOutputs[i]
             << ", " << (result == expectedOutputs[i] ? "PASS" : "FAIL") << endl;
    }

    return 0;
}
