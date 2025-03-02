#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        // ...write your solution here...
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {

            if (count == 0 && s[i] == ' ')
            {
                continue;
            }
            if (s[i] != ' ')
            {
                count++;
            }
            else
            {
                break;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    std::vector<std::pair<std::string, int>> testCases = {
        {"Hello World", 5},
        {"   fly me   to   the moon  ", 4},
        {"luffy is still joyboy", 6},
        {"", 0},
        {"a", 1},
        {"a ", 1},
        {"   ", 0}};

    for (const auto &testCase : testCases)
    {
        int result = solution.lengthOfLastWord(testCase.first);
        std::cout << "Input: \"" << testCase.first << "\" | Expected Output: " << testCase.second << " | Your Output: " << result << std::endl;
    }

    return 0;
}
