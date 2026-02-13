// Leetcode Question 121

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = 1e9;
        int maxi = 0;
        for (int price : prices)
        {
            mini = min(price, mini);
            maxi = max(maxi, price - mini);
        }
        return maxi;
    }
};

// Time Complexity:- O(n)
// Space Complexity:- O(1)