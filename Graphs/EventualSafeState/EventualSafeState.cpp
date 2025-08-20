// question number 802 on leetcode

// the logic is everyone who is a part of the cycle can not be a safe state
// Also everyone that leads to any element of the cycle cannot be the part of the cycle.

class Solution
{
private:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis)
    {
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto it : graph[i])
        {
            if (!vis[it])
            {
                if (dfs(it, graph, vis, pathVis))
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[i] = 0;
        a return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> vis(graph.size(), 0);
        vector<int> pathVis(graph.size(), 0);
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
            {
                dfs(i, graph, vis, pathVis);
            }
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (!pathVis[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};