// Leetcode Question 213: House Robber II
// Time Complexity: O(n)

class Solution
{
private:
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int nottake = prev;
            int curri = max(take, nottake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> temp1;
        vector<int> temp2;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(rob2(temp1), rob2(temp2));
    }
};