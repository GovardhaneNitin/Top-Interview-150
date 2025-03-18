#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = i; j < n - i - 1; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void testRotate()
{
    Solution sol;

    // Test case 1: Basic 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    sol.rotate(matrix1);
    cout << "Test case 1 expected output:\n";
    cout << "7 4 1\n8 5 2\n9 6 3\n";
    cout << "Test case 1 actual output:\n";
    printMatrix(matrix1);

    // Test case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    sol.rotate(matrix2);
    cout << "Test case 2 expected output:\n";
    cout << "15 13  2  5\n14  3  4  1\n12  6  8  9\n16  7 10 11\n";
    cout << "Test case 2 actual output:\n";
    printMatrix(matrix2);

    // Test case 3: 1x1 matrix
    vector<vector<int>> matrix3 = {
        {1}};
    sol.rotate(matrix3);
    cout << "Test case 3 expected output:\n";
    cout << "1\n";
    cout << "Test case 3 actual output:\n";
    printMatrix(matrix3);

    // Test case 4: 2x2 matrix
    vector<vector<int>> matrix4 = {
        {1, 2},
        {3, 4}};
    sol.rotate(matrix4);
    cout << "Test case 4 expected output:\n";
    cout << "3 1\n4 2\n";
    cout << "Test case 4 actual output:\n";
    printMatrix(matrix4);

    // Test case 5: 5x5 matrix with repeated values
    vector<vector<int>> matrix5 = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}};
    sol.rotate(matrix5);
    cout << "Test case 5 expected output:\n";
    cout << "5 4 3 2 1\n5 4 3 2 1\n5 4 3 2 1\n5 4 3 2 1\n5 4 3 2 1\n";
    cout << "Test case 5 actual output:\n";
    printMatrix(matrix5);
}

int main()
{
    testRotate();
    return 0;
}
