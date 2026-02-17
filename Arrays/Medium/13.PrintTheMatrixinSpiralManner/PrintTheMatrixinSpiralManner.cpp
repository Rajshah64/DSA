// Leetcode question 54

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int i = matrix.size();
        int j = matrix[0].size();
        vector<int> ans;
        int top = 0;
        int bottom = i - 1;
        int left = 0;
        int right = j - 1;
        while (top <= bottom && left <= right)
        {
            for (int a = left; a <= right; a++)
            {
                ans.push_back(matrix[top][a]);
                cout << a << endl;
            }
            top++;
            for (int b = top; b <= bottom; b++)
            {
                ans.push_back(matrix[b][right]);
                cout << b << endl;
            }
            right--;

            if (bottom >= top)
            {
                for (int a = right; a >= left; a--)
                {
                    ans.push_back(matrix[bottom][a]);
                    cout << a << endl;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int a = bottom; a >= top; a--)
                {
                    ans.push_back(matrix[a][left]);
                    cout << a << endl;
                }
                left++;
            }
        }
        return ans;
    }
};
// Time Complexity:- O(mn)
// Space Complexity:- O(1) extra (excluding output)