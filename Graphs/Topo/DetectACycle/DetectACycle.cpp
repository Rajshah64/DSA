// we have already solved this before that is to detect a cycle in a graph with the help of dfs .
// But now we will do it with the help of bfs that is kahns algorithm .
// The logic is if there is a cycle the final topo list wont have all the elements
// that is V!= topo.size()where V is the no .of nodes.

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        queue<int> q;

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (topo.size() != V)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};