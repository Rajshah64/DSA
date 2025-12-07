// Articulation Point is the node on whose removal the graph gets disconnected
// the graph breaks into two or more components
// we can find articulation point using DFS and low time concep

// User function Template for C++

class Solution
{
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        vector<int> tin(V);
        vector<int> low(V);

        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i])
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

// Space Complexity:- O(3N) for vis, tin, low and mark arrays  [O(V+2E) for adjacency list(in our case it was already given as input)]
// Time Complexity:- O(V+2E) for dfs and O(N) for traversing mark array