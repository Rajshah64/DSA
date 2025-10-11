// Leetcode question number 63


//Recursive method 
// time complexity is O(2^(m*n))

// class Solution {
//     private:
//         int dfs(int i , int j ,  vector<vector<int>>& grid ){
            
//             if( i <0 || j<0){
//                 return 0;
//             }
//             if(grid[i][j]==1) return 0;
//             if(i ==0 && j==0){
//                 return 1;
//             }
            
//             // as we are going from end to start 
//             // We can go up and left rather than right and down.
//             //as there can be obstacles we have to check first .
//             //if its 1 return 0 and vice versa .  
//             int left =dfs(i-1,j,grid);
//             int up =dfs(i,j-1,grid);            
//             return up+left;
//         }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m= obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         return dfs(m-1,n-1,obstacleGrid);
//     }
// };


//This is the memoized version . 
//Time complexity is O(m*n)
//Space complexity is O(m*n) for dp + O(m+n) for recursive stack 

// class Solution {
//     private:
//         int dfs(int i , int j ,  vector<vector<int>>& grid ,vector<vector<int>>& dp){
            
//             if( i <0 || j<0){
//                 return 0;
//             }
//             if(grid[i][j]==1) return 0;
//             if(i ==0 && j==0){
//                 return 1;
//             }
//             if(dp[i][j]!=-1) return dp[i][j];
//             // as we are going from end to start 
//             // We can go up and left rather than right and down.
//             //as there can be obstacles we have to check first .
//             //if its 1 return 0 and vice versa .  
//             int left =dfs(i-1,j,grid,dp);
//             int up =dfs(i,j-1,grid,dp);            
//             return dp[i][j]=up+left;
//         }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int m= obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
//         vector<vector<int>> dp(m, vector<int>(n,-1));

//         return dfs(m-1,n-1,obstacleGrid,dp);
//     }
// };


//This is the tabulation method 
//Time Complexity O(m*n)
//Space Complexity O(m*n)  (no recursive stack)
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int m= obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
//         vector<vector<int>> dp(m, vector<int>(n,0));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 int up=0,left=0;
//                 if (i == 0 && j == 0) continue;
//                 if(obstacleGrid[i][j]==1) continue;
//                 if(i>0) up=dp[i-1][j];
//                 if(j>0) left=dp[i][j-1];
//                 dp[i][j]=up+left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };



// Now as we go for prev ans in this , we can still space optimize this . 
//If you notice in the end we only want one row as stored values. 
//so we do that . 
//This is tabulation with space optimization
//Time Complexity O(m*n)
//Space Complexity O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m= obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) {
                    curr[j]=0;
                    continue;
                }
                else  if (i == 0 && j == 0) {
                    curr[j]=1;
                }
                else{
                    int up = prev[j];
                    int left= (j>0)? curr[j-1]:0;
                    curr[j]= up + left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};