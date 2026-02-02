// Leetcode Question 1

// Brute Force Approach
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int x = nums[i];
            int rem = target - x;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == rem)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
// Time complexity:- O(N^2)
// Space complexity:- O(1)

