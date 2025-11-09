// Leetcode question 1976 Number of Ways to Arrive at Destination

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const long long MOD = 1000000007;
        int m = roads.size();
        vector<vector<pair<int, int>>> adj(n);
        long long ans = 0;
        // This is basically the count of the smallest time path .

        // store {dest, time to reach}
        // Create adjacency list
        for (int i = 0; i < m; i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                long long wt = it.second;

                // Shorter path found
                if (time + wt < dist[adjNode])
                {
                    dist[adjNode] = time + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                // Same length path found
                else if (time + wt == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};