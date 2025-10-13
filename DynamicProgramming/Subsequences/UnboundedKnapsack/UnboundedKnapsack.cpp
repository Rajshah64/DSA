// Solved on gfg

// This question is very similar to coin change problem

// so I am writing only the tabulation code
//  User function Template for C++

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        vector<int> prev(capacity + 1, 0);
        for (int i = 0; i <= capacity; i++)
        {
            prev[i] = (i / wt[0]) * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(capacity + 1, 0);
            for (int j = 0; j <= capacity; j++)
            {
                int not_take = prev[j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + curr[j - wt[i]];
                curr[j] = max(take, not_take);
            }
            prev = curr;
        }
        // If it's impossible to form the amount, return -1
        return prev[capacity];
    }
};

// we can also space optimize it further by using just one array
//   time complexity: O(n*capacity) where n is the number of items
//   space complexity: O(capacity) for the dp array
//  User function Template for C++

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        vector<int> prev(capacity + 1, 0);
        for (int i = 0; i <= capacity; i++)
        {
            prev[i] = (i / wt[0]) * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                int not_take = prev[j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];
                prev[j] = max(take, not_take);
            }
        }
        // If it's impossible to form the amount, return -1
        return prev[capacity];
    }
};