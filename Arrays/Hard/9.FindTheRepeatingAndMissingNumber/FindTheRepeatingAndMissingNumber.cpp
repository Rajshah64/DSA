// Leetcode Question 2965. Find the Repeating and Missing Number

// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n=grid.size();
//         //This is the original n
//         //To find sum we need n^2
//         int m=n*n;
//         int sum = (m*(m+1))/2;
//         unordered_map<int,int> mp;
//         int rem=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 mp[grid[i][j]]++;
//                 if(mp[grid[i][j]]==1){rem+=grid[i][j];}
//             }
//         }
//         cout<< "rem:"<<rem<<endl;
//         vector<int> ans(2,0);
//         for(auto it: mp){
//             if(it.second==2){
//                 ans[0]=it.first;
//             }
//         }
//         ans[1]=sum-rem;
//         return ans;
//     }
// };
// Time Complexity:O(n^2)
// Space Complexity:O(n)

// Better Approach
//  class Solution {
//  public:
//      vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//          long long n = grid.size();
//          long long m = n * n;
//          long long expectedSum = m * (m + 1) / 2;
//          long long expectedSqSum = m * (m + 1) * (2*m + 1) / 6;
//          long long actualSum = 0;
//          long long actualSqSum = 0;
//          for(int i = 0; i < n; i++){
//              for(int j = 0; j < n; j++){
//                  long long val = grid[i][j];
//                  actualSum += val;
//                  actualSqSum += val * val;
//              }
//          }
//          long long S = actualSum - expectedSum;
//          long long S2 = actualSqSum - expectedSqSum;
//          long long sumXY = S2 / S;
//          long long x = (S + sumXY) / 2;
//          long long y = x - S;
//          return {(int)x, (int)y};
//      }
//  };
//  Time Complexity:- O(n^2)
//  Space Complexity:- O(1)

// Optimized Approach
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = n * n;

        int xorAll = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                xorAll ^= grid[i][j];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            xorAll ^= i;
        }

        int setBit = xorAll & (-xorAll);

        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] & setBit)
                    x ^= grid[i][j];
                else
                    y ^= grid[i][j];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            if (i & setBit)
                x ^= i;
            else
                y ^= i;
        }

        int repeat = 0, missing = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == x)
                    repeat = x;
            }
        }

        if (repeat == x)
        {
            missing = y;
        }
        else
        {
            repeat = y;
            missing = x;
        }

        return {repeat, missing};
    }
};
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)
