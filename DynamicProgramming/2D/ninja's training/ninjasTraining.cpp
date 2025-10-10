// Solved this on gfg as a question called "Geek's Training"

// This is the solution for the problem "Ninja's Training" on Striver SDE sheet
// Here I have done memoization
// Time Complexity: O(N*4*3) ~ O(N)
// Space Complexity: O(N*4) + O(N) ~ O(N)

// class Solution
// {
// private:
//     int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
//     {
//         if (day == 0)
//         {
//             int maxi = 0;
//             for (int task = 0; task < 3; task++)
//             {
//                 if (task != last)
//                 {
//                     maxi = max(maxi, arr[0][task]);
//                 }
//             }
//             return maxi;
//         }
//         if (dp[day][last] != -1)
//             return dp[day][last];
//         int maxi = 0;
//         for (int task = 0; task < 3; task++)
//         {
//             if (task != last)
//             {
//                 int pts = arr[day][task] + f(day - 1, task, arr, dp);
//                 maxi = max(maxi, pts);
//             }
//         }
//         return dp[day][last] = maxi;
//     }

// public:
//     int maximumPoints(vector<vector<int>> &arr)
//     {
//         // Code here
//         vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
//         return f(arr.size() - 1, 3, arr, dp);
//     }
// };

// Here I have done tabulation
// Time Complexity: O(N*4*3) ~ O(N)
// Space Complexity: O(N*4) ~ O(N)
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        vector<vector<int>> dp(arr.size(), vector<int>(4, 0));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][1], arr[0][0]);
        dp[0][3] = max(arr[0][1], max(arr[0][2], arr[0][0]));

        for (int day = 1; day < arr.size(); day++)
        {
            for (int last = 0; last < 4; last++)
            {
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int pt = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], pt);
                    }
                }
            }
        }
        return dp[arr.size() - 1][3];
    }
};

// Here I have done space optimization
// Time Complexity: O(N*4*3) ~ O(N)
// Space Complexity: O(4) ~ O(1)
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        vector<int> dp(4, 0);
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][1], arr[0][0]);
        dp[3] = max(arr[0][1], max(arr[0][2], arr[0][0]));

        for (int day = 1; day < arr.size(); day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        temp[last] = max(temp[last], arr[day][task] + dp[task]);
                    }
                }
            }
            dp = temp;
        }
        return dp[3];
    }
};
