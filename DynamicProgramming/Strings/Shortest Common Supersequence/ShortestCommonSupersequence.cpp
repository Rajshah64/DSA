// Leetcode question 1092
class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill LCS DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Trace back and build SCS directly
        int i = n, j = m;
        string res = "";
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                res.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                res.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters
        while (i > 0)
            res.push_back(str1[i-- - 1 + 1]); // simpler: res.push_back(str1[--i + 1]); optional
        while (j > 0)
            res.push_back(str2[j-- - 1 + 1]);

        reverse(res.begin(), res.end());
        return res;
    }
};

// time complexity: O(n*m)
// space complexity: O(n*m)

// This is the space optimized version
class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill LCS DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Trace back and build SCS directly
        int i = n, j = m;
        string res = "";
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                res.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                res.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters
        while (i > 0)
            res.push_back(str1[--i]);
        while (j > 0)
            res.push_back(str2[--j]);

        reverse(res.begin(), res.end());
        return res;
    }
};
