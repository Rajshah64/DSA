// // Leetcode question 51

// class Solution
// {
// private:
//     bool isSafe(int row, int col, vector<string> &board, int n)
//     {
//

//         int duprow = row;
//         int dupcol = col;

//         while (row >= 0 && col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             row--;
//             col--;
//         }

//         col = dupcol;
//         row = duprow;

//         while (col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             col--;
//         }

//         col = dupcol;
//         row = duprow;

//         while (row < n && col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             col--;
//             row++;
//         }

//         return true;
//     }
//     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
//     {
//         if (col == n)
//         {
//             ans.push_back(board);
//             return;
//         }
//         for (int row = 0; row < n; row++)
//         {
//             if (isSafe(row, col, board, n))
//             {
//                 board[row][col] = 'Q';
//                 solve(col + 1, board, ans, n);
//                 board[row][col] = '.';
//             }
//         }
//     }

// public:
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         solve(0, board, ans, n);
//         return ans;
//     }
// };

// the concept here is that for a queen we have to check for 8 directions.
//         //but as we are placing queens column wise we only need to check left side of the current column.
//         // that is upper left diagonal, left side, lower left diagonal.
//         // time complexity is O(3n) for this function.
//         // we can optimise this further using hashing.
//         // the concept for that is that we will use 3 arrays to keep track of the rows and diagonals.
class Solution
{
private:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        col = dupcol;
        row = duprow;

        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }

        return true;
    }
    void solve(int col, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, leftRow, upperDiagonal, lowerDiagonal, ans, n);
        return ans;
    }
};