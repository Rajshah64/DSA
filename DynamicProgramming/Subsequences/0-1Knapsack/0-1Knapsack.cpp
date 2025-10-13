// solved on gfg

// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

// This is the recursive code with memoization
//  Time Complexity: O(N*W)
//  Space Complexity: O(N*W) + O(N) for recursion stack
class Solution
{
private:
    int f(int ind, int W, vector<int> &val, vector<int> &wt, int sum, vector<vector<int>> &dp)
    {
        // initially (n-1,W);
        if (W == 0)
            return 0;
        if (ind == 0)
        {
            if (wt[ind] <= W)
                return val[ind];
            else
                return 0;
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        // pick condition
        int pick = 0;
        if (wt[ind] <= W)
            pick = val[ind] + f(ind - 1, W - wt[ind], val, wt, sum + val[ind], dp);

        int not_pick = f(ind - 1, W, val, wt, sum, dp);

        return dp[ind][W] = max(pick, not_pick);
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, val, wt, 0, dp);
    }
};

// not putting the only recursive code as it will give TLE.
// Also just remove the dp array and the related lines from the above code to get the recursive code.

// This is the tabulation code
//  Time Complexity: O(N*W)
//  Space Complexity: O(N*W)
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = wt[0]; j <= W; j++)
        {
            dp[0][j] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int pick = 0;
                if (wt[i] <= j)
                    pick = val[i] + dp[i - 1][j - wt[i]];
                int not_pick = dp[i - 1][j];
                dp[i][j] = max(pick, not_pick);
            }
        }

        return dp[n - 1][W];
    }
};

// This is the space optimized code
//  Time Complexity: O(N*W)
//  Space Complexity: O(W)
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = wt.size();
        vector<int> prev(W + 1, 0);

        // The below loop is redundant as its already 0!!
        //  for(int i=0;i<n;i++){
        //      dp[i][0]=0;
        //  }
        for (int j = wt[0]; j <= W; j++)
        {
            prev[j] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(W + 1, 0);
            for (int j = 0; j <= W; j++)
            {
                int pick = 0;
                if (wt[i] <= j)
                    pick = val[i] + prev[j - wt[i]];
                int not_pick = prev[j];
                curr[j] = max(pick, not_pick);
            }
            prev = curr;
        }

        return prev[W];
    }
};