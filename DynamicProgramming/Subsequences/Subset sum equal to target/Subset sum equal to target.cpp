// solved on gfg

// this is the recursive method
class Solution
{
private:
    bool f(int ind, int target, vector<int> &arr)
    {
        if (target == 0)
            return true;
        if (ind == 0)
        {
            if (arr[0] == target)
                return true;
            else
                return false;
        }

        bool take = false;
        if (target >= arr[ind])
        {
            take = f(ind - 1, target - arr[ind], arr);
        }
        bool not_take = f(ind - 1, target, arr);

        return take or not_take;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        return f(n - 1, sum, arr);
    }
};

// this is the memoization method
class Solution
{
private:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool take = false;
        if (target >= arr[ind])
        {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        bool not_take = f(ind - 1, target, arr, dp);

        return dp[ind][target] = take || not_take;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

// This is the tabulation method
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool take = false;
                if (j >= arr[i])
                {
                    take = dp[i - 1][j - arr[i]];
                }
                bool not_take = dp[i - 1][j];
                dp[i][j] = take || not_take;
            }
        }
        return dp[n - 1][sum];
    }
};

// This is the space optimized tabulation method
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for (int j = 1; j <= sum; j++)
            {
                bool take = false;
                if (j >= arr[i])
                {
                    take = prev[j - arr[i]];
                }
                bool not_take = prev[j];
                curr[j] = take || not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
