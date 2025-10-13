// Leetcode question 518: Coin Change 2

// this is the recursive with memoization approach
// time complexity: O(n*amount)
// space complexity: O(n*amount) + O(n) for the recursion stack
class Solution
{
private:
    int f(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            if (target % coins[ind] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // pick condition
        int pick = 0;
        if (coins[ind] <= target)
            pick = f(ind, target - coins[ind], coins, dp);

        int np = f(ind - 1, target, coins, dp);

        return dp[ind][target] = pick + np;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};

// This is the tabulation approach
// time complexity: O(n*amount)
// space complexity: O(n*amount)
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int pick = 0;
                if (coins[i] <= j)
                    pick = dp[i][j - coins[i]];

                int np = dp[i - 1][j];

                dp[i][j] = pick + np;
            }
        }
        return dp[n - 1][amount];
    }
};

// This is the space optimized approach
// time complexity: O(n*amount)
// space complexity: O(amount)
// later Ill upload cause its giving me some error in 3 cases in leetcode even in 1d array