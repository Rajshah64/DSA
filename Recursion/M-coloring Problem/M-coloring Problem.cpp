//solved on gfg


class Solution {
    private:
        bool dfs(int node, vector<vector<int>>& adj, vector<int>& col, int m, int v) {
            if (node == v) return true; 

            for (int c = 1; c <= m; c++) {
                bool canColor = true;
                for (auto &nei : adj[node]) {
                    if (col[nei] == c) {
                        canColor = false;
                        break;
                    }
                }

                if (canColor) {
                    col[node] = c;
                    if (dfs(node + 1, adj, col, m, v)) return true;
                    col[node] = 0; 
                }
            }
            return false;
        }

    public:
        bool graphColoring(int v, vector<vector<int>> &edges, int m) {
            vector<vector<int>> adj(v);
            for (auto &e : edges) {
                int u = e[0], w = e[1];
                adj[u].push_back(w);
                adj[w].push_back(u); 
            }

            vector<int> col(v, 0);
            return dfs(0, adj, col, m, v);
        }
};
