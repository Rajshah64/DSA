// Leetcode question number 931

// This is the recursive method
//  time complexity is O(3^(n*n))
//  space complexity is O(n+n) for recursive stack
// class Solution
// {
// private:
//     int dfs(int i, int j, vector<vector<int>> &matrix)
//     {
//         if (j < 0 || j == matrix.size())
//         {
//             return 1e9;
//         }
//         if (i == matrix.size())
//             return 0;
//         int left = 0, right = 0, cen = 0;
//         left = matrix[i][j] + dfs(i + 1, j - 1, matrix);
//         cen = matrix[i][j] + dfs(i + 1, j, matrix);
//         right = matrix[i][j] + dfs(i + 1, j + 1, matrix);
//         return min(left, min(cen, right));
//     }

// public:
//     int minFallingPathSum(vector<vector<int>> &matrix)
//     {
//         int mini = 1e9;
//         for (int j = 0; j < matrix.size(); j++)
//         {
//             mini = min(mini, dfs(0, j, matrix));
//         }
//         return mini;
//     }
// };

// This is the memoized version .
// Time complexity is O(n*n)
// Space complexity is O(n*n) for dp + O(n+n) for recursive stack
class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j == matrix.size())
        {
            return 1e9;
        }
        if (i == matrix.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = 0, right = 0, cen = 0;
        left = matrix[i][j] + dfs(i + 1, j - 1, matrix, dp);
        cen = matrix[i][j] + dfs(i + 1, j, matrix, dp);
        right = matrix[i][j] + dfs(i + 1, j + 1, matrix, dp);
        return dp[i][j] = min(left, min(cen, right));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int mini = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < matrix.size(); j++)
        {
            mini = min(mini, dfs(0, j, matrix, dp));
        }
        return mini;
    }
};

// this is the tabulation method
//  Time complexity is O(n*n)
//  Space complexity is O(n*n)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {

                int left = 1e9, right = 1e9, cen = 1e9;
                if (j > 0)
                    left = matrix[i][j] + dp[i + 1][j - 1];
                cen = matrix[i][j] + dp[i + 1][j];
                if (j < n - 1)
                    right = matrix[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(left, min(cen, right));
            }
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};

// This is the tabulation method with space optimization
//  Time complexity is O(n*n)
//  Space complexity is O(n)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n);
        prev = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                int left = 1e9, right = 1e9, cen = 1e9;
                if (j > 0)
                    left = matrix[i][j] + prev[j - 1];
                cen = matrix[i][j] + prev[j];
                if (j < n - 1)
                    right = matrix[i][j] + prev[j + 1];
                curr[j] = min(left, min(cen, right));
            }
            prev = curr;
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};