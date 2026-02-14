// Leecode Question 31

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());

        // for example
        // digits 629753
        // we find the problem at 2 as 9 is greater.
        // we swap with next greatest element that is 3
        // the number becomes 639752
        // we reverse  the number from 9 to 2
        // ans is 632579
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)