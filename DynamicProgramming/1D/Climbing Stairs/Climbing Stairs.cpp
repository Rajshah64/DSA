// Leetcode question no. 70

class Solution
{
private:
    int recurse(int target, vector<int> &dp)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        return dp[target] = recurse(target - 1, dp) + recurse(target - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return recurse(n, dp);
    }
};