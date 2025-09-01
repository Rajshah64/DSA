// Done on gfg

// This algorithm will only work on undirected graph
// The only difference between this and dijkstra's algorithm is that
//  here we can have negative weights as well.

// Due to this property, it helps you detect negative cycles in the graph.

// It should take atmost n-1 iterations to find the shortest path.
// if your dist vector relaxes in the nth iteration then there is a negative cycle present.

// User function Template for C++

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // nth relaxation to check negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};
