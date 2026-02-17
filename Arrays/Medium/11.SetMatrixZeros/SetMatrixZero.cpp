// Leetcode Question 73

// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     for (int a = 0; a < m; a++)
//                     {
//                         if (matrix[a][j] != 0)
//                         {
//                             matrix[a][j] = -1;
//                         }
//                     }
//                     for (int a = 0; a < n; a++)
//                     {
//                         if (matrix[i][a] != 0)
//                         {
//                             matrix[i][a] = -1;
//                         }
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == -1)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };
// Time Complexity: O(m*n*(m+n)) where m and n are the number of rows and columns in the matrix respectively. This is because we iterate through each element of the matrix and for each zero element, we iterate through its entire row and column to set the corresponding elements to -1.
// Space Complexity: O(1) since we are modifying the input matrix in place and not using any additional data structures that scale with the size of the input.
// The only problem is if the matrix contains -1 as an element, it will be incorrectly set to 0 in the final step. To avoid this, we can use a different marker value that is not present in the matrix, such as a large positive integer or a special character.

// Better Approach
// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> row(m, 1);
//         vector<int> col(n, 1);
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     row[i] = 0;
//                     col[j] = 0;
//                 }
//             }
//         }

//         for (int i = 0; i < m; i++)
//         {
//             if (row[i] == 0)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (col[i] == 0)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     matrix[j][i] = 0;
//                 }
//             }
//         }
//     }
// };
// Time complixity: O(m*n) + O(m*n) = O(m*n) where m and n are the number of rows and columns in the matrix respectively. This is because we iterate through each element of the matrix twice: once to identify the rows and columns that need to be set to zero, and once to actually set those elements to zero.
// Space Complexity: O(m + n) since we are using two additional arrays to keep track of the rows and columns that need to be set to zero. The size of these arrays is proportional to the number of rows and columns in the input matrix.

// Optimal Approach
// Rather than using additional arrays to store the r and c values, we can use the first row and first column
// of the matrix itself to store this info.
//  and we use one single variable cause one of the cell will overlap for both r and c.

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j == 0)
                    {
                        col0 = 0;
                    }
                    else
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        // We have successfully marked the row and col which are going to be zero .
        // Next step is to actually do it.
        // We start with the inner matrix and then the outer matrix(that means we dont include the first row and col.)
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Now we take care of the first row and the column.
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
// Time Complexity:- O(m*n) + O((m-1)*(n-1)) + O(m)+ O(n)
// Space Compexity:- O(1)