#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // ...write your code here...
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
        }

        int left = 0, right = str.size() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: " << (solution.isPalindrome(test1) ? "true" : "false") << " (Expected: true)" << endl;

    string test2 = "race a car";
    cout << "Test 2: " << (solution.isPalindrome(test2) ? "true" : "false") << " (Expected: false)" << endl;

    string test3 = "";
    cout << "Test 3: " << (solution.isPalindrome(test3) ? "true" : "false") << " (Expected: true)" << endl;

    string test4 = " ";
    cout << "Test 4: " << (solution.isPalindrome(test4) ? "true" : "false") << " (Expected: true)" << endl;

    string test5 = "0P";
    cout << "Test 5: " << (solution.isPalindrome(test5) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}
