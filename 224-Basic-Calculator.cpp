#include <iostream>
#include <string>
#include <cassert>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        // ...write your code here...
        int result = 0, sign = 1, n = s.size();
        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (isdigit(c))
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                result += sign * num;
                --i;
            }
            else if (c == '+')
            {
                sign = 1;
            }
            else if (c == '-')
            {
                sign = -1;
            }
            else if (c == '(')
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result = st.top() * result;
                st.pop();
                result += st.top();
                st.pop();
            }
        }

        return result;
    }
};

void runTests()
{
    Solution solution;

    // Basic test cases
    assert(solution.calculate("1 + 1") == 2);     // Simple addition
    assert(solution.calculate("2 - 1") == 1);     // Simple subtraction
    assert(solution.calculate("2 + 3 - 4") == 1); // Mixed operations

    // Edge cases
    assert(solution.calculate(" 3+5 / 2 ") == 5);            // Spaces and integer division
    assert(solution.calculate("(1+(4+5+2)-3)+(6+8)") == 23); // Nested parentheses
    assert(solution.calculate("2147483647") == 2147483647);  // Large number (INT_MAX)

    // Special cases
    assert(solution.calculate("") == 0);            // Empty input
    assert(solution.calculate(" ") == 0);           // Input with only spaces
    assert(solution.calculate("1-(     -2)") == 3); // Handling negative numbers with spaces

    // Additional edge cases
    assert(solution.calculate("0") == 0);             // Single zero
    assert(solution.calculate("1+0") == 1);           // Addition with zero
    assert(solution.calculate("1-(2+3)") == -4);      // Subtraction with parentheses
    assert(solution.calculate("(((((1+1)))))") == 2); // Deeply nested parentheses

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}