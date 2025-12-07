// leetcode 1192. Critical Connections in a Network
//  the approach used is also known as Tarjan's Algorithm
//  this approach is used to find articulation points and bridges in a graph
//  method is similar to finding bridges in a graph
//  first we use time of insertion to assign each node a time stamp when it is first visited
//  then we use dfs to traverse the graph and for each node we update its low time
//  low time is the lowest time stamp reachable from that node

class Solution
{
private:
    int timer = 1;

private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (vis[it] == 0)
            {
                dfs(it, node, vis, tin, low, adj, bridges);
                low[node] = min(low[node], low[it]);
                // We also have to check if node --- it is a bridge or not
                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;
        dfs(0, -1, vis, tin, low, adj, bridges);
        return bridges;
    }
};

// Space Complexity:- O(V+2E)+ O(3N)
// Time Complexity:- O(V+2E)