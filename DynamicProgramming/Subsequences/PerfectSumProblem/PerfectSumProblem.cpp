// Solved on gfg

// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// This is the recursive code with memoization
//  Time Complexity: O(N*target)
//  Space Complexity: O(N*target) + O(N) for recursion stack
class Solution
{
private:
    int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Correct Base Case: Stop only when all elements are considered.
        if (ind < 0)
        {
            if (target == 0)
            {
                return 1; // Found a valid subset.
            }
            return 0; // This path did not lead to a solution.
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Not pick condition
        int not_pick = f(ind - 1, target, arr, dp);

        // Pick condition
        int pick = 0;
        if (target >= arr[ind])
        {
            pick = f(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = pick + not_pick;
    }

public:
    int perfectSum(std::vector<int> &arr, int target)
    {
        // Start the recursion from the last index.
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};

// This is the tabulation code
// Time Complexity: O(N*target)
// Space Complexity: O(N*target)
class Solution
{
public:
    int perfectSum(std::vector<int> &arr, int target)
    {
        // Start the recursion from the last index.
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // Base case: sum = 0 is always possible (empty subset)
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        // Base case: first element
        if (arr[0] <= target)
            dp[0][arr[0]] += 1;
        for (int ind = 1; ind < n; ind++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                int not_pick = dp[ind - 1][sum];
                // Pick condition
                int pick = 0;
                if (sum >= arr[ind])
                {
                    pick = dp[ind - 1][sum - arr[ind]];
                }
                dp[ind][sum] = pick + not_pick;
            }
        }
        return dp[n - 1][target];
    }
};

// This is the space optimized code
// Time Complexity: O(N*target)
// Space Complexity: O(target)
class Solution
{
public:
    int perfectSum(std::vector<int> &arr, int target)
    {
        // Start the recursion from the last index.
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        // Base case: sum = 0 is always possible (empty subset)
        prev[0] = 1;

        // Base case: first element
        if (arr[0] <= target)
            prev[arr[0]] += 1;
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(target + 1, 0);
            curr[0] = 1;
            for (int sum = 0; sum <= target; sum++)
            {
                int not_pick = prev[sum];
                // Pick condition
                int pick = 0;
                if (sum >= arr[ind])
                {
                    pick = prev[sum - arr[ind]];
                }
                curr[sum] = pick + not_pick;
            }
            prev = curr;
        }
        return prev[target];
    }
};