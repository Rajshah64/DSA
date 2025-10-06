//Leetcode Question 198: House Robber

// class Solution {
// private:
//     int dfs(int ind, vector<int>& nums){
//         if(ind ==0) return nums[0];
//         if(ind <0) return 0;
//         //if(dp[ind]!=-1) return dp[ind];

//         int pick= nums[ind]+ dfs(ind-2,nums);

//         int not_pick= 0 + dfs(ind-1,nums);

//         return max(pick  ,not_pick);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int result= dfs(nums.size()-1,nums);
//         return result;
//     }
// };

// This is memoization.
// time complexity becomes O(n)
//  class Solution {
//  private:
//      int dfs(int ind, vector<int>& nums,vector<int>& dp){
//          if(ind ==0) return nums[0];
//          if(ind <0) return 0;
//          if(dp[ind]!=-1) return dp[ind];

//         int pick= nums[ind]+ dfs(ind-2,nums,dp);

//         int not_pick= 0 + dfs(ind-1,nums,dp);

//         return dp[ind]=max(pick  ,not_pick);
//     }
// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         int result= dfs(nums.size()-1,nums,dp);
//         return result;
//     }
// };

// Tabulation
// This is the most optimized approach .
// IT is both time and space optimized .
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int nottake = prev;
            int curri = max(take, nottake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};