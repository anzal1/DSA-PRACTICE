#include <bits/stdc++.h>
using namespace std;

bool nqueens(vector<vector<int>> &board, int n, int row, int col)
{
    if (row == n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, row, i))
        {
            board[row][i] = 1;
            if (nqueens(board, n, row + 1, 0))
                return true;
            board[row][i] = 0;
        }
    }
    return false;
}
bool isSafe(vector<vector<int>> &board, int n, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}