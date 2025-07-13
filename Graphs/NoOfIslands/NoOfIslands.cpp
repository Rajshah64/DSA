class Solution
{
private:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int dir = 0; dir < 4; dir++)
        {
            int n1 = i + dx[dir];
            int n2 = j + dy[dir];

            if (n1 >= 0 && n1 < n && n2 >= 0 && n2 < m && !vis[n1][n2] && grid[n1][n2] == '1')
            {
                dfs(n1, n2, vis, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();    // no. of rows.
        int m = grid[0].size(); // no. of columns.
        // vector<vector<vector<pair<int,int>>>> adj(n, vector<vector<pair<int, int>>>(m));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if((j+1)<m && grid[i][j+1]=='1'){
        //             adj[i][j].push_back({i,j+1});
        //             adj[i][j+1].push_back({i,j});
        //         }
        //         if((i+1)<n && grid[i+1][j]=='1'){
        //             adj[i][j].push_back({i+1,j});
        //             adj[i+1][j].push_back({i,j});
        //         }
        //         if((i-1)>=0 && grid[i-1][j]=='1'){
        //             adj[i][j].push_back({i-1,j});
        //             adj[i-1][j].push_back({i,j});
        //         }
        //         if((j-1)>=0 && grid[i][j-1]=='1'){
        //             adj[i][j].push_back({i,j-1});
        //             adj[i][j-1].push_back({i,j});
        //         }

        //     }
        // }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};