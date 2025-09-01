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

// Same algorithm using set

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<vector<vector<int>>> adj(V); // create the adjacency list

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
        set<pair<int, int>> st;
        // vector<int> dist(V,INT_MAX);
        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int d = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int v = it[0];
                int wt = it[1];

                if (d + wt < dist[v])
                {
                    // this if condition is for checking if that node is already visited or not .
                    // IF it is then there is no point in checking the distance again .
                    // so we remove the already existing pair from the set (yes there would be one present )
                    // The reason it will be present because we are in the if condition where
                    // dist[now] < dist[last interation], so it would still be in the set.
                    if (dist[v] != INT_MAX)
                    {
                        st.erase({dist[v], v});
                    }
                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};
