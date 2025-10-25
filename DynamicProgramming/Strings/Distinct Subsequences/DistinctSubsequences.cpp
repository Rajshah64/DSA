// Leetcode question 115

// this is the recursive plus memoization approach
// time complexity is O(n*m)
// space complexity is O(n*m) + O(n+m) for the dp array and the recursion stack
class Solution
{
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }

        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};

// This is the tabulation approach
//  time complexity is O(n*m)
//  space complexity is O(n*m) for the dp array
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
// converted from int to long long to avoid overflow for large inputs

// This is the 1D array space optimized approach
//  time complexity is O(n*m)
//  space complexity is O(m) for the dp array
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<double> curr(m + 1, 0);
            curr[0] = 1;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};

// space optimized version using only one array
//  time complexity is O(n*m)
//  space complexity is O(m) for the dp array
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            prev[0] = 1;
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    prev[j] = (__int128)prev[j - 1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};
