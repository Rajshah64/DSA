// Leetcode 216

class Solution
{
private:
    void comb(int ind, int sz, int target, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (target == 0)
        {
            if (temp.size() == sz)
            {
                ans.push_back(temp);
            }
            return;
        }
        if (ind > 9 || target < 0)
            return;

        temp.push_back(ind);
        comb(ind + 1, sz, target - ind, ans, temp);
        temp.pop_back();
        comb(ind + 1, sz, target, ans, temp);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        comb(1, k, n, ans, temp);
        return ans;
    }
};