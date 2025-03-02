#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // ...write you code here...
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution solution;

    // Test case 1: Normal case
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test case 1: " << solution.longestCommonPrefix(strs1) << " (Expected: 'fl')" << endl;

    // Test case 2: No common prefix
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test case 2: " << solution.longestCommonPrefix(strs2) << " (Expected: '')" << endl;

    // Test case 3: All strings are the same
    vector<string> strs3 = {"test", "test", "test"};
    cout << "Test case 3: " << solution.longestCommonPrefix(strs3) << " (Expected: 'test')" << endl;

    // Test case 4: One string is empty
    vector<string> strs4 = {"", "b", "c"};
    cout << "Test case 4: " << solution.longestCommonPrefix(strs4) << " (Expected: '')" << endl;

    // Test case 5: All strings are empty
    vector<string> strs5 = {"", "", ""};
    cout << "Test case 5: " << solution.longestCommonPrefix(strs5) << " (Expected: '')" << endl;

    // Test case 6: Only one string
    vector<string> strs6 = {"single"};
    cout << "Test case 6: " << solution.longestCommonPrefix(strs6) << " (Expected: 'single')" << endl;

    return 0;
}
