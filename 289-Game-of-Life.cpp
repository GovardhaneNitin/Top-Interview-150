#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        // ...write your code here...
        int rows = board.size();
        if (rows == 0)
            return;
        int cols = board[0].size();

        vector<vector<int>> nextBoard = board;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int liveNeighbors = 0;
                for (int x = max(0, i - 1); x <= min(rows - 1, i + 1); ++x)
                {
                    for (int y = max(0, j - 1); y <= min(cols - 1, j + 1); ++y)
                    {
                        if (x == i && y == j)
                            continue;
                        liveNeighbors += board[x][y];
                    }
                }

                if (board[i][j] == 1)
                {
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                    {
                        nextBoard[i][j] = 0;
                    }
                }
                else
                {
                    if (liveNeighbors == 3)
                    {
                        nextBoard[i][j] = 1;
                    }
                }
            }
        }

        board = nextBoard;
    }
};

void printBoard(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void runTestCases()
{
    Solution sol;

    // Test case 1: Basic test case
    vector<vector<int>> board1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    sol.gameOfLife(board1);
    cout << "Test case 1 - Expected output:" << endl;
    cout << "0 0 0" << endl;
    cout << "1 0 1" << endl;
    cout << "0 1 1" << endl;
    cout << "0 1 0" << endl;
    cout << "Actual output:" << endl;
    printBoard(board1);

    // Test case 2: Edge case with all cells dead
    vector<vector<int>> board2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    sol.gameOfLife(board2);
    cout << "Test case 2 - Expected output:" << endl;
    cout << "0 0 0" << endl;
    cout << "0 0 0" << endl;
    cout << "0 0 0" << endl;
    cout << "Actual output:" << endl;
    printBoard(board2);

    // Test case 3: Edge case with all cells alive
    vector<vector<int>> board3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    sol.gameOfLife(board3);
    cout << "Test case 3 - Expected output:" << endl;
    cout << "1 0 1" << endl;
    cout << "0 0 0" << endl;
    cout << "1 0 1" << endl;
    cout << "Actual output:" << endl;
    printBoard(board3);

    // Test case 4: Special case with a single cell
    vector<vector<int>> board4 = {
        {1}};
    sol.gameOfLife(board4);
    cout << "Test case 4 - Expected output:" << endl;
    cout << "0" << endl;
    cout << "Actual output:" << endl;
    printBoard(board4);

    // Test case 5: Special case with two cells
    vector<vector<int>> board5 = {
        {1, 1}};
    sol.gameOfLife(board5);
    cout << "Test case 5 - Expected output:" << endl;
    cout << "0 0" << endl;
    cout << "Actual output:" << endl;
    printBoard(board5);

    // Test case 6: Large input
    vector<vector<int>> board6(50, vector<int>(50, 1));
    sol.gameOfLife(board6);
    cout << "Test case 6 - Expected output: (50x50 grid with alternating 1s and 0s)" << endl;
    cout << "Actual output:" << endl;
    printBoard(board6);
}

int main()
{
    runTestCases();
    return 0;
}
