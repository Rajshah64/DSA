// solved on gfg

// this is the recursive code
class Solution
{
private:
    int f(int i, int j, string &s1, string &s2, int count)
    {
        if (i < 0 || j < 0)
        {
            return count;
        }

        if (s1[i] == s2[j])
            count = f(i - 1, j - 1, s1, s2, count + 1);

        int a = f(i - 1, j, s1, s2, 0);
        int b = f(i, j - 1, s1, s2, 0);
        return max(count, max(a, b));
    }

public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();
        return f(n - 1, m - 1, s1, s2, 0);
    }
};

// this is the memoization code
class Solution
{
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &ans)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp, ans); // extend substring
            ans = max(ans, dp[i][j]);                        // update global answer
        }
        else
        {
            dp[i][j] = 0; // mismatch → substring breaks
        }

        // explore remaining branches (start fresh)
        f(i - 1, j, s1, s2, dp, ans);
        f(i, j - 1, s1, s2, dp, ans);

        return dp[i][j];
    }

public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        f(n - 1, m - 1, s1, s2, dp, ans);
        return ans;
    }
};
// time complexity: O(n*m)
// space complexity: O(n*m) + O(n+m) for recursion stack

// this is the tabulation code
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0; // this is created as a global maximum length of substring.
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
// time complexity: O(n*m)
// space complexity: O(n*m)

// this is the space optimized code
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0);
        int ans = 0; // this is created as a global maximum length of substring.
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};
// time complexity: O(n*m)
// space complexity: O(m)