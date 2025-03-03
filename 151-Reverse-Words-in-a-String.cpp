#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // ...write your code here...
        vector<string> arr;
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (word != "")
                {
                    arr.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += s[i];
            }
        }
        if (word != "")
        {
            arr.push_back(word);
        }

        string result = "";

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            result += arr[i];
            if (i != 0)
            {
                result += " ";
            }
        }

        return result;
    }
};

void runTests()
{
    Solution solution;

    // Test case 1: Regular case
    string input1 = "the sky is blue";
    string expected1 = "blue is sky the";
    assert(solution.reverseWords(input1) == expected1);

    // Test case 2: Leading and trailing spaces
    string input2 = "  hello world  ";
    string expected2 = "world hello";
    assert(solution.reverseWords(input2) == expected2);

    // Test case 3: Multiple spaces between words
    string input3 = "a good   example";
    string expected3 = "example good a";
    assert(solution.reverseWords(input3) == expected3);

    // Test case 4: Single word
    string input4 = "hello";
    string expected4 = "hello";
    assert(solution.reverseWords(input4) == expected4);

    // Test case 5: Empty string
    string input5 = "";
    string expected5 = "";
    assert(solution.reverseWords(input5) == expected5);

    // Test case 6: String with only spaces
    string input6 = "     ";
    string expected6 = "";
    assert(solution.reverseWords(input6) == expected6);

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
