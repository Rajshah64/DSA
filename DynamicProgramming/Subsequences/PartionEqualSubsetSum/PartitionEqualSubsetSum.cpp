// Leetcode question 416: Partition Equal Subset Sum

// This question is very similar to the subset sum equal to target question
// only thing is that the target is sum/2
// So we can directly use the code of subset sum equal to target question

class Solution
{
private:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;
            for (int j = 1; j <= sum; j++)
            {
                bool take = false;
                if (j >= arr[i])
                {
                    take = prev[j - arr[i]];
                }
                bool not_take = prev[j];
                curr[j] = take || not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false; // as odd sum can not be divided into 2 equal halves.
        int target = sum / 2;

        return isSubsetSum(nums, target);
    }
};