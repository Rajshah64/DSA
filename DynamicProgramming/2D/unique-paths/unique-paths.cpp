// Leetcode question number 62

// Memoization
// Time complexity O(mxn)
// Space Complexity O(mxn) fro dp array + O(m+n) for recursive stack.
//  class Solution {
//      private:
//          int dfs(int i , int j , int m,int n,vector<vector<int>>& dp){
//              if(i==(m -1) && j==(n-1)){
//                  return 1;
//              }
//              if(dp[i][j]!=-1)return dp[i][j];
//              int paths = 0;
//              if( (i+1)<m ){
//                  paths+= dfs(i+1,j,m,n,dp);
//              }

//             if( (j+1)<n ){
//                 paths+=dfs(i,j+1,m,n,dp);
//             }
//             return dp[i][j]=paths;
//         }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return dfs(0,0,m,n,dp);
//     }
// };

// Tabulation method
// Time complexity O(m*n)
// Space complexity O(m*n)
//  class Solution {
//  public:
//      int uniquePaths(int m, int n) {
//          vector<vector<int>> dp(m,vector<int>(n,0));
//          dp[m-1][n-1] = 1;

//         for(int i = m-1; i >= 0; i--){
//         for(int j = n-1; j >= 0; j--){
//             if(i+1 < m) dp[i][j] += dp[i+1][j]; // down
//             if(j+1 < n) dp[i][j] += dp[i][j+1]; // right
//         }
//         }

//         return dp[0][0];
// }
// };

// Tabulation Method space optimized
// Time complexity O(m*n)
// Space complexity O(n)
//  class Solution {
//  public:
//      int uniquePaths(int m, int n) {
//          vector<int> dp(n,1);

//         for(int i=m-2;i>=0;i--){
//             for(int j=n-2;j>=0;j--){
//                 dp[j]+=dp[j+1];
//             }
//         }
//         return dp[0];
//     }
// };

// Direct method without dp only combinatorics
// Time complexity O(min(m,n))
// Space complexity O(1)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long res = 1;
        int N = m + n - 2; // total moves
        int k = m - 1;     // choose down moves

        // Compute C(N, k) using iterative multiplication to avoid large factorials
        for (int i = 1; i <= k; ++i)
        {
            res = res * (N - k + i) / i;
        }

        return (int)res;
    }
};