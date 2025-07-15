#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j}, 0);
                    vis[i][j] = 2;
                }
            }
        }
        int tm = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.first.first;
            int c = q.first.second;
            int t = q.second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int n1 = r + dx[i];
                int n2 = c + dy[i];
                if (n1 >= 0 && n1 < n && n2 >= 0 && n2 < m && grid[n1][n2] == 1 && vis[n1][n2] == 0)
                {
                    vis[n1][n2] = 2;
                    grid[n1][n2] = 2;
                    q.push({{n1, n2}, t + 1});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1; // If any orange is still fresh
                }
            }
        }
        return tm;
    }
};

int main()
{
    return 0;
}