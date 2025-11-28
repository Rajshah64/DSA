// User function Template for C++
// Kruskal's Algorithm to find Minimum Spanning Tree (MST) weight
// using Disjoint Set Union (DSU) data structure
// Time Complexity: O(E log E + E * α(V)) where E is the number of edges, V is the number of vertices
// The concept is based on sorting edges and using DSU to avoid cycles
// Space Complexity: O(V) for DSU data structure
class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // path compression
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {

        // for(int i=0;i<edges.size();i++){
        //     cout<< edges[i][0]<<" "<< edges[i][1]<<" "<< edges[i][2]<<" "<<endl;
        // }
        // code here
        vector<pair<int, pair<int, int>>> fedges;

        for (auto it : edges)
        {
            int adjNode = it[1];
            int wt = it[2];
            int node = it[0];

            fedges.push_back({wt, {node, adjNode}});
        }

        DisjointSet ds(V);
        sort(fedges.begin(), fedges.end());

        int mstW = 0;

        for (auto it : fedges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstW += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstW;
    }
};
