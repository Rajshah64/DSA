class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // code here
        vector<int> dist(adj.size(), 1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        vector<int> ans(adj.size(), -1);
        for (int i = 0; i < adj.size(); i++)
        {
            if (dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};