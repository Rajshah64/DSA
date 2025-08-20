// This question is solved on gfg

// User function Template for C++

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int row0, int col0)
    {
        vis[row][col] = 1;
        temp.push_back({row - row0, col - col0});
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, vis, grid, temp, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    dfs(i, j, vis, grid, temp, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
