#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int node, int col)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (!dfs(graph, color, it, !col))
                {
                    return false;
                }
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        bool ans;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(graph, color, i, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}