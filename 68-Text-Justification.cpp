#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // ...write your code here...
        vector<string> result;
        int n = words.size();
        int start = 0;
        while (start < n)
        {
            int end = start;
            int totalLength = 0;
            while (end < n && totalLength + words[end].length() + end - start <= maxWidth)
            {
                totalLength += words[end].length();
                end++;
            }
            int totalSpaces = maxWidth - totalLength;
            int totalWords = end - start;
            string line = "";
            if (totalWords == 1 || end == n)
            {
                for (int i = start; i < end; i++)
                {
                    line += words[i];
                    if (i < end - 1)
                    {
                        line += " ";
                    }
                }
                while (line.length() < maxWidth)
                {
                    line += " ";
                }
            }
            else
            {
                int spaces = totalSpaces / (totalWords - 1);
                int extraSpaces = totalSpaces % (totalWords - 1);
                for (int i = start; i < end; i++)
                {
                    line += words[i];
                    if (i < end - 1)
                    {
                        for (int j = 0; j < spaces; j++)
                        {
                            line += " ";
                        }
                        if (extraSpaces > 0)
                        {
                            line += " ";
                            extraSpaces--;
                        }
                    }
                }
            }
            result.push_back(line);
            start = end;
        }
        return result;
    }
};

void printVector(const vector<string> &vec)
{
    for (const string &str : vec)
    {
        cout << "\"" << str << "\"" << endl;
    }
}

int main()
{
    Solution solution;
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution.fullJustify(words1, maxWidth1);
    cout << "Test Case 1:" << endl;
    printVector(result1);
    cout << "Expected Output:" << endl;
    cout << "\"This    is    an\"" << endl;
    cout << "\"example  of text\"" << endl;
    cout << "\"justification.  \"" << endl;

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution.fullJustify(words2, maxWidth2);
    cout << "Test Case 2:" << endl;
    printVector(result2);
    cout << "Expected Output:" << endl;
    cout << "\"What   must   be\"" << endl;
    cout << "\"acknowledgment  \"" << endl;
    cout << "\"shall be        \"" << endl;

    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    vector<string> result3 = solution.fullJustify(words3, maxWidth3);
    cout << "Test Case 3:" << endl;
    printVector(result3);
    cout << "Expected Output:" << endl;
    cout << "\"Science  is  what we\"" << endl;
    cout << "\"understand      well\"" << endl;
    cout << "\"enough to explain to\"" << endl;
    cout << "\"a  computer.  Art is\"" << endl;
    cout << "\"everything  else  we\"" << endl;
    cout << "\"do                  \"" << endl;

    return 0;
}
