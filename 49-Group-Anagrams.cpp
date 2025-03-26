#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagrams;
        for (const string &str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto &pair : anagrams)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};

void printResult(const vector<vector<string>> &result)
{
    for (const auto &group : result)
    {
        cout << "[ ";
        for (const auto &str : group)
        {
            cout << str << " ";
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Test Case 1: Basic test case with multiple anagrams
    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Test Case 1: ";
    printResult(solution.groupAnagrams(test1));
    // Expected Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    // Test Case 2: Single word
    vector<string> test2 = {"hello"};
    cout << "Test Case 2: ";
    printResult(solution.groupAnagrams(test2));
    // Expected Output: [["hello"]]

    // Test Case 3: Empty input
    vector<string> test3 = {};
    cout << "Test Case 3: ";
    printResult(solution.groupAnagrams(test3));
    // Expected Output: []

    // Test Case 4: All words are anagrams
    vector<string> test4 = {"abc", "bca", "cab"};
    cout << "Test Case 4: ";
    printResult(solution.groupAnagrams(test4));
    // Expected Output: [["abc","bca","cab"]]

    // Test Case 5: No anagrams
    vector<string> test5 = {"dog", "cat", "bird"};
    cout << "Test Case 5: ";
    printResult(solution.groupAnagrams(test5));
    // Expected Output: [["dog"],["cat"],["bird"]]

    // Test Case 6: Words with repeated characters
    vector<string> test6 = {"aabb", "bbaa", "abab", "baba", "aaab"};
    cout << "Test Case 6: ";
    printResult(solution.groupAnagrams(test6));
    // Expected Output: [["aabb","bbaa","abab","baba"],["aaab"]]

    // Test Case 7: Large input
    vector<string> test7(1000, "abc");
    test7.push_back("def");
    cout << "Test Case 7: ";
    printResult(solution.groupAnagrams(test7));
    // Expected Output: [["abc","abc",... (998 more times)],["def"]]

    return 0;
}
