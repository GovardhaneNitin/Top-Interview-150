#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // ...write your code here...
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution solution;
    vector<pair<string, bool>> testCases = {
        // Basic test cases
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},

        // Edge cases
        {"", true},                     // Empty string
        {"(((((((((())))))))))", true}, // Deeply nested valid parentheses
        {"(((((((((()))))))))", false}, // Deeply nested invalid parentheses
        {"[", false},                   // Single opening bracket
        {"]", false},                   // Single closing bracket

        // Special cases
        {"(((((((((())))))))))[]{}", true},  // Mixed valid parentheses
        {"(((((((((())))))))))[]}{", false}, // Mixed invalid parentheses
        {"{}{}{}{}{}{}{}{}{}{}", true},      // Repeated valid patterns
        {"(((((((((((", false},              // Only opening brackets
        {")))))))))))", false},              // Only closing brackets
    };

    for (const auto &testCase : testCases)
    {
        string input = testCase.first;
        bool expected = testCase.second;
        bool result = solution.isValid(input);
        cout << "Input: " << input << " | Expected: " << (expected ? "true" : "false")
             << " | Result: " << (result ? "true" : "false") << endl;
    }

    return 0;
}
