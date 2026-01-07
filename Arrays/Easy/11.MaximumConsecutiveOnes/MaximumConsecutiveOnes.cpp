// Leetcode Question 485
// TC:- O(N)
// SC:- O(1)
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int maxcnt = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                // cout<< "the current number is 1"<<endl;
            }
            else
            {
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
                // cout<< "the current number is 0"<<endl;
            }
        }
        return max(maxcnt, cnt);
    }
};


