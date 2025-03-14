#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (s.empty() || words.empty())
            return result;

        int wordLength = words[0].length();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        if (s.length() < totalLength)
            return result;

        unordered_map<string, int> wordFrequency;
        for (const string &word : words)
        {
            wordFrequency[word]++;
        }

        for (int i = 0; i < wordLength; ++i)
        {
            int left = i, count = 0;
            unordered_map<string, int> seenWords;
            for (int j = i; j <= (int)s.length() - wordLength; j += wordLength)
            {
                string word = s.substr(j, wordLength);
                if (wordFrequency.find(word) != wordFrequency.end())
                {
                    seenWords[word]++;
                    count++;
                    while (seenWords[word] > wordFrequency[word])
                    {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    if (count == wordCount)
                    {
                        result.push_back(left);
                    }
                }
                else
                {
                    seenWords.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return result;
    }
};

void runTests()
{
    Solution solution;

    // Test case 1: Basic test case
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> expected1 = {0, 9};
    assert(solution.findSubstring(s1, words1) == expected1);

    // Test case 2: Words not in string
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> expected2 = {};
    assert(solution.findSubstring(s2, words2) == expected2);

    // Test case 3: Empty string
    string s3 = "";
    vector<string> words3 = {"foo", "bar"};
    vector<int> expected3 = {};
    assert(solution.findSubstring(s3, words3) == expected3);

    // Test case 4: Empty words
    string s4 = "barfoothefoobarman";
    vector<string> words4 = {};
    vector<int> expected4 = {};
    assert(solution.findSubstring(s4, words4) == expected4);

    // Test case 5: Single character words
    string s5 = "aaaaaa";
    vector<string> words5 = {"a", "a"};
    vector<int> expected5 = {0, 1, 2, 3, 4};
    assert(solution.findSubstring(s5, words5) == expected5);

    // Test case 6: Large input
    string s6 = string(10000, 'a') + "b";
    vector<string> words6 = {"a", "b"};
    vector<int> expected6 = {9999};
    assert(solution.findSubstring(s6, words6) == expected6);

    // Test case 7: Repeated words
    string s7 = "wordgoodgoodgoodbestword";
    vector<string> words7 = {"good", "good"};
    vector<int> expected7 = {4, 8};
    assert(solution.findSubstring(s7, words7) == expected7);

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
