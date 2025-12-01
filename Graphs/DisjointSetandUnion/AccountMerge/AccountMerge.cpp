// Leetcode question number 721: Account Merge

class DisjointSet
{

public:
    vector<int> parent, rank, size;
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // This first part is used to map each email to a unique node using Disjoint Set
        // This means that if two emails belong to the same person, they will be connected in the Disjoint Set

        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mapMailNode.find(accounts[i][j]) == mapMailNode.end())
                {
                    mapMailNode[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(i, mapMailNode[accounts[i][j]]);
                }
            }
        }
        // this is the second part
        // Here as the name suggests , we are merging all the email from the map having same ultimate parent node
        vector<vector<string>> Mergedmail(n);
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            Mergedmail[node].push_back(mail);
        }

        // this is the last part where we are preparing the final answer
        // Here we are basically adding the name of the person at the start of each merged email list and sorting the emails

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (Mergedmail[i].size() == 0)
                continue;
            sort(Mergedmail[i].begin(), Mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : Mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
