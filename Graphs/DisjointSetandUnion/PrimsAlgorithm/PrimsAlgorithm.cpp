// solved on gfg

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edN = iter.second;
                if (!vis[adjNode])
                {
                    pq.push({edN, adjNode});
                }
            }
        }
        return sum;
    }
};

// In this question they only asked the sum of the weights of the edges in the MST.
// If you want to store the edges as well, you can do it like this:
//  you can store the parent of each node that you put in the priority queue.
//  When you pop a node from the priority queue, you can add the edge between the node and its parent to a result list if the parent is not -1 (indicating that it's not the starting node).
//  Here is an example of how you can modify the code to store the edges of the MST:
// class Solution {
//   public:
//     pair<int, vector<vector<int>>> spanningTree(int V, vector<vector<int>>& edges) {
//         // Step 1: Build adjacency list
//         vector<vector<pair<int,int>>> adj(V);
//         for(auto it: edges) {
//             int u = it[0];
//             int v = it[1];
//             int w = it[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }

//         // Step 2: Min-heap (weight, {node, parent})
//         priority_queue<pair<int, pair<int,int>>,
//                        vector<pair<int, pair<int,int>>>,
//                        greater<pair<int, pair<int,int>>>> pq;

//         vector<int> vis(V, 0);
//         vector<vector<int>> mstEdges; // To store edges of MST
//         int sum = 0;

//         // Start with node 0, parent = -1
//         pq.push({0, {0, -1}});

//         while(!pq.empty()) {
//             auto it = pq.top();
//             pq.pop();

//             int wt = it.first;
//             int node = it.second.first;
//             int parent = it.second.second;

//             if(vis[node]) continue;

//             vis[node] = 1;
//             sum += wt;

//             // If it’s not the first node, store the edge
//             if(parent != -1) {
//                 mstEdges.push_back({parent, node, wt});
//             }

//             // Traverse adjacent nodes
//             for(auto iter: adj[node]) {
//                 int adjNode = iter.first;
//                 int edW = iter.second;

//                 if(!vis[adjNode]) {
//                     pq.push({edW, {adjNode, node}});
//                 }
//             }
//         }

//         return {sum, mstEdges};
//     }
// };
