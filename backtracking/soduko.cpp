#include <bits/stdc++.h>
using namespace std;

// solve the given sudoku
void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuRec(board, 0, 0);
}

void solveSudokuRec(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return;
    if (col == 9)
    {
        solveSudokuRec(board, row + 1, 0);
        return;
    }
    if (board[row][col] != '.')
    {
        solveSudokuRec(board, row, col + 1);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(board, row, col, i + '0'))
        {
            board[row][col] = i + '0';
            solveSudokuRec(board, row, col + 1);
            board[row][col] = '.';
        }
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
    {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}