// Leetcode Question 136

// TC:- O(N)
// SC:- O(1)
// Using XOR property
// This is the bit manipulation version
// If we XOR 2 same numbers it becomes zero
// and anything XOR with 0 is the same number.
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};


