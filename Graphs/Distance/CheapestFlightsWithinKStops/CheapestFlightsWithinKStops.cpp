// Leetcode question 787: Cheapest Flights Within K Stops

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (steps > k)
                continue;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edN = it.second;

                if (cost + edN < dist[adjNode] && steps <= k)
                {
                    dist[adjNode] = cost + edN;
                    q.push({steps + 1, {adjNode, cost + edN}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};