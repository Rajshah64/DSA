// Problem 1020
class Solution
{
private:
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = true;
        grid[x][y] = 2;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int n1 = x + dx[i];
            int n2 = y + dy[i];
            if (n1 >= 0 && n1 < n && n2 >= 0 && n2 < m && !vis[n1][n2] && grid[n1][n2] == 1)
            {
                dfs(n1, n2, grid, vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
            {
                dfs(i, 0, grid, vis);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, grid, vis);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
            {
                dfs(0, j, grid, vis);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            {
                dfs(n - 1, j, grid, vis);
            }
        }

        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};