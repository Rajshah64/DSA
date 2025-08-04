// Problem 130

class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        int n = board.size();
        int m = board[0].size();
        vis[x][y] = true;
        board[x][y] = 'S';
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int n1 = x + dx[i];
            int n2 = y + dy[i];

            if (n1 < n && n1 >= 0 && n2 < m && n2 >= 0 && !vis[n1][n2] && board[n1][n2] == 'O')
            {

                dfs(n1, n2, board, vis);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);
            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, board, vis);
        }

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);
            if (board[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(n - 1, j, board, vis);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};