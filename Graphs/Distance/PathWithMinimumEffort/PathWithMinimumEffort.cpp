// Leetcode question 1631: Path With Minimum Effort

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>> // min-heap
            >
            pq;
        //{max abs diff ,{x,y}}
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int eff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newM = max(eff, abs(heights[nx][ny] - heights[x][y]));
                    if (newM < dist[nx][ny])
                    {
                        dist[nx][ny] = newM;
                        pq.push({newM, {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};