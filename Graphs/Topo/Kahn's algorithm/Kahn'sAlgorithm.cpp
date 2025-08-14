// Kahns algorithm
// Topological Sorting is a linear ordering of vertices su h that if there is an edge between u and v, u appears before v in the ordering .
// Topo sort only works on direct acyclic graph
// In this alogrithm we will be using indegree concept.
// indegree means that no of incoming edges to a node.

class Solution
{
    // step0 --> Frist insert all the nodes with indegree 0 in the queue .
    // step1 --> traverse through the adj list of that node , and remove it(so just decrease the indegree from the other node).
    // step2 --> IF the node has indegree 0 after this transaction, then add it to the queue .
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        queue<int> q;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

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
        return topo;
    }
};
