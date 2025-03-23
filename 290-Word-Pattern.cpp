#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        // ...write your code here...
        vector<string> words;
        string word;
        for (char c : s)
        {
            if (c == ' ')
            {
                words.push_back(word);
                word.clear();
            }
            else
            {
                word += c;
            }
        }
        words.push_back(word);

        if (pattern.size() != words.size())
        {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i)
        {
            char c = pattern[i];
            const string &w = words[i];

            if (charToWord.count(c) && charToWord[c] != w)
            {
                return false;
            }
            if (wordToChar.count(w) && wordToChar[w] != c)
            {
                return false;
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};

void runTests()
{
    Solution solution;

    // Basic test cases
    assert(solution.wordPattern("abba", "dog cat cat dog") == true);
    assert(solution.wordPattern("abba", "dog cat cat fish") == false);
    assert(solution.wordPattern("aaaa", "dog cat cat dog") == false);
    assert(solution.wordPattern("abba", "dog dog dog dog") == false);

    // Edge cases
    assert(solution.wordPattern("a", "dog") == true);
    assert(solution.wordPattern("a", "dog cat") == false);
    assert(solution.wordPattern("", "") == true);
    assert(solution.wordPattern("abc", "dog cat") == false);
    assert(solution.wordPattern("abc", "dog cat cat") == false);

    // Special cases
    assert(solution.wordPattern("abc", "dog cat fish") == true);
    assert(solution.wordPattern("aaa", "dog dog dog") == true);
    assert(solution.wordPattern("aaa", "dog dog cat") == false);
    assert(solution.wordPattern("abc", "dog dog dog") == false);

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
