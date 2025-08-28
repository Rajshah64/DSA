// question was solved on gfg

class Solution
{
private:
    vector<int> topoSort(int K, vector<vector<int>> &adj)
    {
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++)
            for (int v : adj[i])
                indegree[v]++;
        queue<int> q;
        for (int i = 0; i < K; i++)
            if (indegree[i] == 0)
                q.push(i);
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : adj[u])
                if (--indegree[v] == 0)
                    q.push(v);
        }
        return topo;
    }

public:
    string findOrder(vector<string> &words)
    {
        vector<vector<int>> adj(26);
        vector<int> used(26, 0);
        for (auto &w : words)
            for (char c : w)
                used[c - 'a'] = 1;

        bool seen[26][26] = {};
        for (int i = 0; i + 1 < (int)words.size(); i++)
        {
            string &a = words[i], &b = words[i + 1];
            int len = min(a.size(), b.size());
            int j = 0;
            while (j < len && a[j] == b[j])
                j++;
            if (j == len)
            {
                if (a.size() > b.size())
                    return "";
                continue;
            }
            int u = a[j] - 'a', v = b[j] - 'a';
            if (!seen[u][v])
            {
                adj[u].push_back(v);
                seen[u][v] = true;
            }
        }

        vector<int> topo = topoSort(26, adj);
        string ans;
        int totalUsed = 0, inTopoUsed = 0;
        for (int i = 0; i < 26; i++)
            totalUsed += used[i];
        for (int u : topo)
            if (used[u])
            {
                ans += char(u + 'a');
                inTopoUsed++;
            }
        if (inTopoUsed != totalUsed)
            return "";
        return ans;
    }
};
