// Leetcode question 79

class Solution
{
private:
    bool dfs(int idx, int row, int col, vector<vector<char>> &board, string word, vector<vector<bool>> &vis)
    {
        if (idx == word.size() - 1)
        {
            return true;
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] == word[idx + 1] && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = true;
                if (dfs(idx + 1, nrow, ncol, board, word, vis))
                    return true;
                vis[nrow][ncol] = false;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if (dfs(0, i, j, board, word, vis))
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};