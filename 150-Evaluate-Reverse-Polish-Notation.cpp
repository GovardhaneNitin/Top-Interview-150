#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // ...write your code here...
        vector<int> stack;
        for (const string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                if (token == "+")
                    stack.push_back(a + b);
                else if (token == "-")
                    stack.push_back(a - b);
                else if (token == "*")
                    stack.push_back(a * b);
                else if (token == "/")
                    stack.push_back(a / b);
            }
            else
            {
                stack.push_back(stoi(token));
            }
        }
        return stack.back();
    }
};

int main()
{
    Solution solution;

    // Test Case 1: Basic test case with addition and multiplication
    vector<string> test1 = {"2", "1", "+", "3", "*"};
    cout << "Test Case 1: " << solution.evalRPN(test1) << " (Expected: 9)" << endl;

    // Test Case 2: Basic test case with division and subtraction
    vector<string> test2 = {"4", "13", "5", "/", "+"};
    cout << "Test Case 2: " << solution.evalRPN(test2) << " (Expected: 6)" << endl;

    // Test Case 3: Single number input
    vector<string> test3 = {"42"};
    cout << "Test Case 3: " << solution.evalRPN(test3) << " (Expected: 42)" << endl;

    // Test Case 4: Negative numbers
    vector<string> test4 = {"-4", "2", "/", "3", "-"};
    cout << "Test Case 4: " << solution.evalRPN(test4) << " (Expected: -5)" << endl;

    // Test Case 5: Large input values
    vector<string> test5 = {"100000", "200000", "+", "300000", "*"};
    cout << "Test Case 5: " << solution.evalRPN(test5) << " (Expected: 90000000000)" << endl;

    // Test Case 6: Empty input (edge case)
    vector<string> test6 = {};
    cout << "Test Case 6: " << solution.evalRPN(test6) << " (Expected: 0 or error handling)" << endl;

    // Test Case 7: Complex expression
    vector<string> test7 = {"10", "6", "9", "3", "/", "-", "*", "17", "+", "5", "+"};
    cout << "Test Case 7: " << solution.evalRPN(test7) << " (Expected: 22)" << endl;

    return 0;
}