// Leetcode question number 1091: Shortest Path in Binary Matrix

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        if (grid[0][0] == 1 || grid[n - 1][n - 1])
            return -1;
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        while (!q.empty())
        {
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            // int dx[]={-1,0,1};
            // int dy[]={-1,0,1};
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        continue;
                    }
                    else
                    {
                        int nx = x + i;
                        int ny = y + j;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !grid[nx][ny])
                        {
                            if (dist[x][y] + 1 < dist[nx][ny])
                            {
                                dist[nx][ny] = dist[x][y] + 1;
                                q.push({dist[x][y] + 1, {nx, ny}});
                            }
                        }
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == 1e9)
            return -1;
        else
            return dist[n - 1][n - 1];
    }
};