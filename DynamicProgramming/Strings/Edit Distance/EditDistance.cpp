// Leetcode question 72

// This is the recursive method for finding the edit distance between two strings
class Solution
{
private:
    int f(int i, int j, string &s, string &t)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (s[i] == t[j])
            return f(i - 1, j - 1, s, t);
        return 1 + min(f(i - 1, j, s, t), min(f(i, j - 1, s, t), f(i - 1, j - 1, s, t)));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return f(n - 1, m - 1, word1, word2);
    }
};
// Time Complexity:- O(2^(n+m))
// Space Complexity:- O(n+m)  (recursion stack space)

// This is the memoization method for finding the edit distance between two strings
class Solution
{
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return f(i - 1, j - 1, s, t, dp);
        return dp[i][j] = 1 + min(f(i - 1, j, s, t, dp), min(f(i, j - 1, s, t, dp), f(i - 1, j - 1, s, t, dp)));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
};
// Time Complexity:- O(n*m)
// Space Complexity:- O(n*m) + O(n+m)  (dp array + recursion stack space)

// This is the tabulation method for finding the edit distance between two strings
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++)
            dp[i][0] = i; // delete all
        for (int j = 0; j <= m; j++)
            dp[0][j] = j; // insert all

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // no operation needed
                }
                else
                {
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // delete
                                       dp[i][j - 1],    // insert
                                       dp[i - 1][j - 1] // replace
                                   });
                }
            }
        }

        return dp[n][m];
    }
};
// Time Complexity:- O(n*m)
// Space Complexity:- O(n*m)

// This is the space optimized tabulation method for finding the edit distance between two strings
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        // Base cases
        for (int j = 0; j <= m; j++)
            prev[j] = j; // insert all

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1]; // no operation needed
                }
                else
                {
                    curr[j] = 1 + min({
                                      prev[j],     // delete
                                      curr[j - 1], // insert
                                      prev[j - 1]  // replace
                                  });
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};