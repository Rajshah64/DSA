// Problem 542
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto [i, j] = q.front().first;
            int steps = q.front().second;
            q.pop();

            ans[i][j] = steps;

            for (int k = 0; k < 4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj])
                {
                    vis[ni][nj] = true;
                    q.push({{ni, nj}, steps + 1});
                }
            }
        }

        return ans;
    }
};
