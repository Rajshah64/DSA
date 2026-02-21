// Leetcoode Question 48

// The Brute force solution is to take another matrix and copy the elements in the required order.
// This will take O(N^2) time and O(N^2) space.
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         //first create a new matrix
//         int n=matrix.size();
//         vector<vector<int>> ans(n,vector<int>(n,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 ans[j][(n-1)-i]=matrix[i][j];
//             }
//         }
//         matrix=ans;
//     }
// };

// Optimal approach without using extra space.
// We frist take transpose of the matrix and then reverse each row to get the required output.
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // First we transpose
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // After this we basically reverse all vector inside each outer vector
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// Time Complexity:- O(N^2) for transposing + O(N^2) for reversing each row
// Space Complexity:- O(1) as we are doing it in place.