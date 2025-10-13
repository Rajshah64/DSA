// Leetcode 322. Coin Change

// this is a recursive + memoization approach
// time complexity: O(n*amount) where n is the number of coins
// space complexity: O(amount) for the dp array + O(amount) for the recursion stack space
class Solution
{
private:
    int f(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            // If target can be exactly divided by this coin,
            // we can make up the amount with (target / coin) coins
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9; // impossible to form the target with this coin
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // int pick =1e9;
        // if(coins[ind]<=target) pick=(target/coins[ind])+f(ind-1,target - ((target/coins[ind])*coins[ind]),coins);
        // int not_pick=0+ f(ind-1,target, coins );
        // Choice 1: Do NOT take this coin → move to smaller index
        int not_take = f(ind - 1, target, coins, dp);

        // Choice 2: Take this coin → stay at same index (unbounded)
        int take = 1e9;
        if (coins[ind] <= target)
            take = 1 + f(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = min(take, not_take);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        // If it's impossible to form the amount, return -1
        return (ans >= 1e9) ? -1 : ans;
    }
};

// This is a tabulation approach
//  time complexity: O(n*amount) where n is the number of coins
//  space complexity: O(n*amount) for the dp array
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int not_take = dp[i - 1][j];
                // Choice 2: Take this coin → stay at same index (unbounded)
                int take = 1e9;
                if (coins[i] <= j)
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, not_take);
            }
        }
        // If it's impossible to form the amount, return -1
        return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
    }
};

// This is a space optimized approach
//  time complexity: O(n*amount) where n is the number of coins
//  space complexity: O(amount) for the dp array
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                prev[i] = i / coins[0];
            }
            else
            {
                prev[i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(amount + 1, 1e9);
            for (int j = 0; j <= amount; j++)
            {
                int not_take = prev[j];
                int take = 1e9;
                if (coins[i] <= j)
                    take = 1 + curr[j - coins[i]];
                curr[j] = min(take, not_take);
            }
            prev = curr;
        }
        // If it's impossible to form the amount, return -1
        return (prev[amount] >= 1e9) ? -1 : prev[amount];
    }
};