class Solution
{
private:
    void dfs(int i, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(i);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        //adjacency list 
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
