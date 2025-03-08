#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // ...write your code here...
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (s[i] == t[j])
            {
            i++;
            }
            j++;
        }
        return i == m;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << "Test case 1: " << (solution.isSubsequence(s1, t1) ? "true" : "false") << " (Expected: true)" << endl;

    // Test case 2
    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << "Test case 2: " << (solution.isSubsequence(s2, t2) ? "true" : "false") << " (Expected: false)" << endl;

    // Edge case 1: Empty s
    string s3 = "";
    string t3 = "ahbgdc";
    cout << "Edge case 1: " << (solution.isSubsequence(s3, t3) ? "true" : "false") << " (Expected: true)" << endl;

    // Edge case 2: Empty t
    string s4 = "abc";
    string t4 = "";
    cout << "Edge case 2: " << (solution.isSubsequence(s4, t4) ? "true" : "false") << " (Expected: false)" << endl;

    // Edge case 3: Both s and t are empty
    string s5 = "";
    string t5 = "";
    cout << "Edge case 3: " << (solution.isSubsequence(s5, t5) ? "true" : "false") << " (Expected: true)" << endl;

    // Edge case 4: s is longer than t
    string s6 = "abcdef";
    string t6 = "abc";
    cout << "Edge case 4: " << (solution.isSubsequence(s6, t6) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}
