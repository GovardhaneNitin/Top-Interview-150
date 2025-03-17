#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // ...write your code here...
        vector<int> result;
        if (matrix.empty())
        {
            return result;
        }

        int startRow = 0, endRow = matrix.size() - 1;
        int startCol = 0, endCol = matrix[0].size() - 1;

        while (startRow <= endRow && startCol <= endCol)
        {
            // Traverse right
            for (int i = startCol; i <= endCol; ++i)
            {
                result.push_back(matrix[startRow][i]);
            }
            startRow++;

            // Traverse down
            for (int i = startRow; i <= endRow; ++i)
            {
                result.push_back(matrix[i][endCol]);
            }
            endCol--;

            // Traverse left
            if (startRow <= endRow)
            {
                for (int i = endCol; i >= startCol; --i)
                {
                    result.push_back(matrix[endRow][i]);
                }
            }
            endRow--;

            // Traverse up
            if (startCol <= endCol)
            {
                for (int i = endRow; i >= startRow; --i)
                {
                    result.push_back(matrix[i][startCol]);
                }
            }
            startCol++;
        }

        return result;
    }
};

// Function to print the vector
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Test case 1: Basic test case
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<int> result1 = solution.spiralOrder(matrix1);
    cout << "Test case 1: ";
    printVector(result1);
    // Expected output: 1 2 3 6 9 8 7 4 5

    // Test case 2: Single row
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4}};
    vector<int> result2 = solution.spiralOrder(matrix2);
    cout << "Test case 2: ";
    printVector(result2);
    // Expected output: 1 2 3 4

    // Test case 3: Single column
    vector<vector<int>> matrix3 = {
        {1},
        {2},
        {3},
        {4}};
    vector<int> result3 = solution.spiralOrder(matrix3);
    cout << "Test case 3: ";
    printVector(result3);
    // Expected output: 1 2 3 4

    // Test case 4: Empty matrix
    vector<vector<int>> matrix4 = {};
    vector<int> result4 = solution.spiralOrder(matrix4);
    cout << "Test case 4: ";
    printVector(result4);
    // Expected output: (empty output)

    // Test case 5: Matrix with one element
    vector<vector<int>> matrix5 = {
        {1}};
    vector<int> result5 = solution.spiralOrder(matrix5);
    cout << "Test case 5: ";
    printVector(result5);
    // Expected output: 1

    // Test case 6: Rectangular matrix (more rows)
    vector<vector<int>> matrix6 = {
        {1, 2, 3},
        {4, 5, 6}};
    vector<int> result6 = solution.spiralOrder(matrix6);
    cout << "Test case 6: ";
    printVector(result6);
    // Expected output: 1 2 3 6 5 4

    // Test case 7: Rectangular matrix (more columns)
    vector<vector<int>> matrix7 = {
        {1, 2},
        {3, 4},
        {5, 6}};
    vector<int> result7 = solution.spiralOrder(matrix7);
    cout << "Test case 7: ";
    printVector(result7);
    // Expected output: 1 2 4 6 5 3

    return 0;
}
