// Solved on gfg

// class Solution {
//     private:
//         int ans(int ind,vector<int>& height,vector<int>& dp){
//              if (ind == 0) return 0;
//              if(dp[ind]!=-1) return dp[ind];

//             int lft = ans(ind - 1, height,dp) + abs(height[ind] - height[ind - 1]);
//             int right = INT_MAX;
//             if (ind > 1) {
//                 right = ans(ind - 2, height,dp) + abs(height[ind] - height[ind - 2]);
//         }

//         return dp[ind]=min(lft, right);
//         }
//   public:
//     int minCost(vector<int>& height) {
//         // Code here
//         vector<int> dp(height.size(),-1);
//         return ans(height.size()-1,height,dp);
//     }
// };

// The above process is memoization . We have to convert it to tabulation

// class Solution {
//   public:
//     int minCost(vector<int>& height) {
//         int n=height.size()-1;
//         vector<int> dp(height.size(),0);
//         dp[0]=0;
//         for(int i=1;i<height.size();i++){
//             int fs= dp[i-1]+ abs(height[i]-height[i-1]);
//             int ss= INT_MAX;
//             if(i > 1){
//                 ss= dp[i-2]+ abs(height[i]-height[i-2]);
//             }
//             dp[i]=min(fs,ss);
//         }

//         return dp[n];

//     }
// };

// We can still reduce the space as we are still using O(n).
// The below is the final code with space optimization

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int prev = 0;
        int prev2 = 0;
        for (int i = 1; i < height.size(); i++)
        {
            int fs = prev + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
            {
                ss = prev2 + abs(height[i] - height[i - 2]);
            }
            int curri = min(fs, ss);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};


//Now the modified question is can we jump k steps back instead of 2 steps back
// The below is the code for that

