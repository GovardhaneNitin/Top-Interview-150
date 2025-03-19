#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // ...write your code here...
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;

        vector<bool> row_zero(rows, false);
        vector<bool> col_zero(cols, false);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
            if (matrix[i][j] == 0)
            {
                row_zero[i] = true;
                col_zero[j] = true;
            }
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
            if (row_zero[i] || col_zero[j])
            {
                matrix[i][j] = 0;
            }
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
    cout << endl;
}

void testSetZeroes()
{
    Solution sol;

    // Test case 1: Basic test case
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    sol.setZeroes(matrix1);
    cout << "Test case 1 expected output:" << endl;
    cout << "1 0 1" << endl;
    cout << "0 0 0" << endl;
    cout << "1 0 1" << endl;
    cout << "Test case 1 actual output:" << endl;
    printMatrix(matrix1);

    // Test case 2: Matrix with multiple zeroes
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    sol.setZeroes(matrix2);
    cout << "Test case 2 expected output:" << endl;
    cout << "0 0 0 0" << endl;
    cout << "0 4 5 0" << endl;
    cout << "0 3 1 0" << endl;
    cout << "Test case 2 actual output:" << endl;
    printMatrix(matrix2);

    // Test case 3: Matrix with no zeroes
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    sol.setZeroes(matrix3);
    cout << "Test case 3 expected output:" << endl;
    cout << "1 2 3" << endl;
    cout << "4 5 6" << endl;
    cout << "7 8 9" << endl;
    cout << "Test case 3 actual output:" << endl;
    printMatrix(matrix3);

    // Test case 4: Empty matrix
    vector<vector<int>> matrix4 = {};
    sol.setZeroes(matrix4);
    cout << "Test case 4 expected output:" << endl;
    cout << "Empty matrix" << endl;
    cout << "Test case 4 actual output:" << endl;
    printMatrix(matrix4);

    // Test case 5: Single element matrix with zero
    vector<vector<int>> matrix5 = {{0}};
    sol.setZeroes(matrix5);
    cout << "Test case 5 expected output:" << endl;
    cout << "0" << endl;
    cout << "Test case 5 actual output:" << endl;
    printMatrix(matrix5);

    // Test case 6: Single element matrix with non-zero
    vector<vector<int>> matrix6 = {{1}};
    sol.setZeroes(matrix6);
    cout << "Test case 6 expected output:" << endl;
    cout << "1" << endl;
    cout << "Test case 6 actual output:" << endl;
    printMatrix(matrix6);
}

int main()
{
    testSetZeroes();
    return 0;
}
