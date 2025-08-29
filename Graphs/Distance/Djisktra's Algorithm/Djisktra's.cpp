// User Function Template
// Question solved on gfg
// This is using priority queue or min heap
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<vector<vector<int>>> adj(V); // create the adjacency list
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // the above statement is how you create a min heap.
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // above loop creates a for loop

        vector<int> dist(V, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top()[1];
            pq.pop();

            for (auto it : adj[u])
            {
                int v = it[0];
                int wt = it[1];

                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
