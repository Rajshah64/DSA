// Leetcode question 64

// recursive method
//  time complexity is O(2^(m*n))
//  space complexity is O(m+n) for recursive stack
//  class Solution
//  {
//  private:
//      int dfs(int i, int j, vector<vector<int>> &grid)
//      {
//          if (i < 0 || j < 0)
//              return 1e9;
//          if (i == 0 && j == 0)
//          {
//              return grid[0][0];
//          }
//          int up = grid[i][j] + dfs(i - 1, j, grid);
//          int left = grid[i][j] + dfs(i, j - 1, grid);

//         return min(up, left);
//     }

// public:
//     int minPathSum(vector<vector<int>> &grid)
//     {
//         int x = grid.size();
//         int y = grid[0].size();
//         return dfs(x - 1, y - 1, grid);
//     }
// };

// This is the memoized version .
// Time complexity is O(m*n)
// Space complexity is O(m*n) for dp + O(m+n) for recursive stack
class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 1e9;
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = grid[i][j] + dfs(i - 1, j, grid, dp);
        int left = grid[i][j] + dfs(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<int>> dp(x, vector<int>(y, -1));
        return dfs(x - 1, y - 1, grid, dp);
    }
};

// This is the tabulation method
// Time Complexity O(m*n)
// Space Complexity O(m*n) (no recursive stack)
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<int>> dp(x, vector<int>(y, 0));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                int up = 1e9, left = 1e9;
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                    continue;
                }
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
        return dp[x - 1][y - 1];
    }
};

// This is the space optimized method
// Time Complexity O(m*n)
// Space Complexity O(n) (no recursive stack)
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        vector<int> prev(y, 0);
        for (int i = 0; i < x; i++)
        {
            vector<int> curr(y, 0);
            for (int j = 0; j < y; j++)
            {
                int up = 1e9, left = 1e9;
                if (i == 0 && j == 0)
                {
                    curr[j] = grid[0][0];
                    continue;
                }
                if (i > 0)
                    up = grid[i][j] + prev[j];
                if (j > 0)
                    left = grid[i][j] + curr[j - 1];
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[y - 1];
    }
};