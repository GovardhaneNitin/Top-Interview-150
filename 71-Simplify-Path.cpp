#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        // write your code here
        vector<string> stack;
        string dir;
        stringstream ss(path);

        while (getline(ss, dir, '/'))
        {
            if (dir == "" || dir == ".")
                continue;
            if (dir == "..")
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else
            {
                stack.push_back(dir);
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); ++i)
        {
            result += stack[i];
            if (i != stack.size() - 1)
                result += "/";
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Basic test cases
    cout << "Test Case 1: /home/ -> Expected: /home, Actual: " << sol.simplifyPath("/home/") << endl;
    cout << "Test Case 2: /../ -> Expected: /, Actual: " << sol.simplifyPath("/../") << endl;
    cout << "Test Case 3: /home//foo/ -> Expected: /home/foo, Actual: " << sol.simplifyPath("/home//foo/") << endl;
    cout << "Test Case 4: /a/./b/../../c/ -> Expected: /c, Actual: " << sol.simplifyPath("/a/./b/../../c/") << endl;

    // Edge cases
    cout << "Test Case 5: /../../../../ -> Expected: /, Actual: " << sol.simplifyPath("/../../../../") << endl;
    cout << "Test Case 6: /a/b/c/../.. -> Expected: /a, Actual: " << sol.simplifyPath("/a/b/c/../..") << endl;
    cout << "Test Case 7:  -> Expected: /, Actual: " << sol.simplifyPath("") << endl;
    cout << "Test Case 8: / -> Expected: /, Actual: " << sol.simplifyPath("/") << endl;

    // Special cases
    cout << "Test Case 9: /a/b/c -> Expected: /a/b/c, Actual: " << sol.simplifyPath("/a/b/c") << endl;
    cout << "Test Case 10: /a/../../b/../c//.// -> Expected: /c, Actual: " << sol.simplifyPath("/a/../../b/../c//.//") << endl;

    return 0;
}
