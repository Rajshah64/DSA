// Leetcode question 120

// recursive method
//  time complexity is O(2^(m*n))
//  space complexity is O(m+n) for recursive stack
class Solution
{
private:
    int dfs(int ind, vector<vector<int>> &triangle, int lvl)
    {
        if (lvl == triangle.size())
            return 0;

        int left = triangle[lvl][ind] + dfs(ind, triangle, lvl + 1);
        int right = triangle[lvl][ind] + dfs(ind + 1, triangle, lvl + 1);

        return min(left, right);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        return dfs(0, triangle, 0);
    }
};

// This is the memoized version .
// Time complexity is O(m*n)
// Space complexity is O(m*n) for dp + O(m+n) for recursive stack
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};

// This is the tabulation method with space optimization
// Time complexity is O(m*n)
// Space complexity is O(n)
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> prev(n, 0);
        for (int j = 0; j < n; j++)
        {
            prev[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(i + 1, 0);
            for (int j = 0; j <= i; j++)
            {
                curr[j] = triangle[i][j] + min(prev[j], prev[j + 1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};