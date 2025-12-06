// This problem is also known as Kosaraju's algorithm for finding strongly connected components in a directed graph.
// They are only valid for directed graph.

// The algorithm is :-
//  1. sort all the edges according to their finishing times in decreasing order.
//  2. Reverse the direction of all the edges.
//  3. Do DFS according to the sorted order on the reversed graph.

// Position this line where user code will be pasted.
class Solution
{
private:
    void dfs1(int i, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (vis[it] == 0)
            {
                dfs1(it, vis, adj, st);
            }
        }
        st.push(i);
    }
    void dfs2(int i, vector<int> &vis, vector<vector<int>> &adjT)
    {
        vis[i] = 1;
        for (auto it : adjT[i])
        {
            if (vis[it] == 0)
            {
                dfs2(it, vis, adjT);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        int V = adj.size();
        // step 1 is to sort the nodes according to the finishing time
        // in descending order.
        // We will use a stack and do dfs
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs1(i, vis, adj, st);
            }
        }

        // after this step we will have the stack of nodes with descending finishing time
        // now we have to reverse each edges.

        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                dfs2(node, vis, adjT);
                scc++;
            }
        }
        return scc;
    }
};
