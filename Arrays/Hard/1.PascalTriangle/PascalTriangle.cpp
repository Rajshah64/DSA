// Leetcode Question 118

// There are 3 types of questions that can be asked for this .
// 1. Given a row number, return the row of the Pascal's triangle.
// 2. Given a row number and column number, return the value at that position in the Pascal's triangle.
// 3. Given a number of rows, return the whole Pascal's triangle.

// For the Second question we can use the formula nCr = n!/r!*(n-r)! but it will give TLE for large values of n and r. So we can use the property of Pascal's triangle that is nCr = nC(r-1) * (n-r+1)/r. This will give us the value in O(r) time complexity.
// So we can use this property to calculate the value at any position in the Pascal's triangle in O(r) time complexity.
class Solution
{
public:
    int nCr(int n, int r)
    {
        // code here
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }
};
// Time Complexity: O(r)
// Space Complexity: O(1)





// For the third question we can use sort of dp
// Optimal Solution
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         if(numRows==1) return {{1}};
//         vector<vector<int>> ans;
//         ans.push_back({1});
//         ans.push_back({1,1});
//         //it will not enter the loop for numrows=2.
//         for(int i=3;i<=numRows;i++){
//             vector<int>temp(i,0);
//             temp[0]=temp[i-1]=1;
//             for(int j=0;j<i-2;j++){
//                 temp[j+1]=ans[i-2][j]+ans[i-2][j+1];
//             }
//             ans.push_back(temp);

//         }
//         return ans;
//     }
// };
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)



// For the first question we can use the same approach as the third question but we will only store the current row and the previous row. So we can optimize the space complexity to O(1).