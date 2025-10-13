// solved on gfg

// Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset.
// Let the sum of the elements of these two subsets be sum1 and sum2.
// Given a difference d,
// count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d.

// This is the recursive code
class Solution
{
private:
    int f(int ind, int totSum, vector<int> &arr, int d, int currSum)
    {
        // base condtion
        if (ind < 0)
        {
            int newSum = totSum - currSum;
            if (currSum >= newSum && (currSum - newSum) == d)
                return 1;
            return 0;
        }
        // pick condition
        int pick = f(ind - 1, totSum, arr, d, currSum + arr[ind]);

        // not pick condition
        int not_pick = f(ind - 1, totSum, arr, d, currSum);

        // return statement
        return pick + not_pick;
    }

public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int totSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }
        return f(n - 1, totSum, arr, d, 0);
    }
};
// Time Complexity: O(2^N)
// Space Complexity: O(N) for recursion stack

// This is the memoization code
// Time Complexity: O(N*totSum)
// Space Complexity: O(N*totSum) + O(N) for recursion stack
class Solution
{
private:
    int f(int ind, int totSum, vector<int> &arr, int d, int currSum, vector<vector<int>> &dp)
    {
        // base condtion
        if (ind < 0)
        {
            int newSum = totSum - currSum;
            if (currSum >= newSum && (currSum - newSum) == d)
                return 1;
            return 0;
        }
        if (dp[ind][currSum] != -1)
            return dp[ind][currSum];
        // pick condition
        int pick = f(ind - 1, totSum, arr, d, currSum + arr[ind], dp);

        // not pick condition
        int not_pick = f(ind - 1, totSum, arr, d, currSum, dp);

        // return statement
        return dp[ind][currSum] = pick + not_pick;
    }

public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int totSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
        return f(n - 1, totSum, arr, d, 0, dp);
    }
};

// This is the tabulation code
//  Time Complexity: O(N*totSum)
//  Space Complexity: O(N*totSum)
class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();
        int totSum = 0;
        for (int num : arr)
            totSum += num;

        if (totSum < d || (totSum + d) % 2 != 0)
            return 0;
        int target = (totSum + d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case: first element
        if (arr[0] == 0)
        {
            dp[0][0] = 2; // pick or not pick zero
        }
        else
        {
            dp[0][0] = 1; // sum 0: not pick
            if (arr[0] <= target)
                dp[0][arr[0]] = 1; // sum arr[0]: pick
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                int not_pick = dp[i - 1][j];
                int pick = (j >= arr[i]) ? dp[i - 1][j - arr[i]] : 0;
                dp[i][j] = pick + not_pick;
            }
        }

        return dp[n - 1][target];
    }
};

// This is the space optimized code
//  Time Complexity: O(N*totSum)
//  Space Complexity: O(totSum)
class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();
        int totSum = 0;
        for (int num : arr)
            totSum += num;

        if (totSum < d || (totSum + d) % 2 != 0)
            return 0;
        int target = (totSum + d) / 2;

        vector<int> prev(target + 1, 0);

        // Base case: first element
        if (arr[0] == 0)
        {
            prev[0] = 2; // pick or not pick zero
        }
        else
        {
            prev[0] = 1; // sum 0: not pick
            if (arr[0] <= target)
                prev[arr[0]] = 1; // sum arr[0]: pick
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(target + 1, 0);
            for (int j = 0; j <= target; j++)
            {
                int not_pick = prev[j];
                int pick = (j >= arr[i]) ? prev[j - arr[i]] : 0;
                curr[j] = pick + not_pick;
            }
            prev = curr;
        }

        return prev[target];
    }
};

// I just realised that this question is exactly same as the subset sum with given target question
//  where the target is (totalSum + d)/2
// so we dont need to calculate the total sum and do all this stuff
//  we can directly use the code of subset sum with given target question
