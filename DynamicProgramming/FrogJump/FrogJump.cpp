// Solved on gfg

class Solution
{
private:
    int ans(int ind, vector<int> &height, vector<int> &dp)
    {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int lft = ans(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
        int right = INT_MAX;
        if (ind > 1)
        {
            right = ans(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }

        return dp[ind] = min(lft, right);
    }

public:
    int minCost(vector<int> &height)
    {
        // Code here
        vector<int> dp(height.size(), -1);
        return ans(height.size() - 1, height, dp);
    }
};