// solved on leetcode question 1143

// This is the recursive method
class Solution
{
private:
    int dfs(int i, int j, string &s, string &t)
    {
        if (i < 0 || j < 0)
            return 0;
        if (s[i] == t[j])
            return 1 + dfs(i - 1, j - 1, s, t);
        retrun max(dfs(i, j - 1, s, t), dfs(i - 1, j, s, t));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        return dfs(n - 1, m - 1, text1, text2);
    }
};

// This will always give TLE for large inputs
// This is the memoization method
// class Solution
// {
// private:
//     int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
//     {
//         if (i < 0 || j < 0)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i] == t[j])
//             return dp[i][j] = 1 + dfs(i - 1, j - 1, s, t, dp);
//         return dp[i][j] = max(dfs(i, j - 1, s, t, dp), dfs(i - 1, j, s, t, dp));
//     }

// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return dfs(n - 1, m - 1, text1, text2, dp);
//     }
// };
class Solution
{
private:
    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + dfs(i - 1, j - 1, s, t, dp);
        return dp[i][j] = max(dfs(i, j - 1, s, t, dp), dfs(i - 1, j, s, t, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return dfs(n, m, text1, text2, dp);
    }
};
// time complexity: O(n*m)
// space complexity: O(n*m) + O(n+m) for recursion stack

// This is the tabulation method
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};
// time complexity: O(n*m)
// space complexity: O(n*m)

// This is the space optimized tabulation method
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
// time complexity: O(n*m)
// space complexity: O(m)