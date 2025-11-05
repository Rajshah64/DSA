// Leetcode question 743: Network Delay Time

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : times)
        {
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
            // basically we are pushing an pair of{dest, time to reach}.
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1}); // {distance, node}
        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currDist = it.first;
            int node = it.second;

            if (currDist > dist[node])
                continue;

            for (auto iter : adj[node])
            {
                int next = iter.first;
                int time = iter.second;
                if (time + currDist < dist[next])
                {
                    dist[next] = time + currDist;
                    pq.push({time + currDist, next});
                }
            }
        }
        int mx = 0;
        for (auto it : dist)
        {
            if (it == 1e9)
                return -1;
            mx = max(mx, it);
        }
        return mx;
    }
};
// Time Complexity: O((V + E) log V)
// Where V is the number of vertices and E is the number of edges in the graph.