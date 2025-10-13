// Leetcode question 2035: Partition Array Into Two Arrays to Minimize Sum Difference

class Solution
{
private:
    int totalSum;
    int minDiff;

    void f(int ind, vector<int> &nums, vector<int> &temp)
    {
        if (ind < 0)
        {
            // When we have selected exactly half the elements
            if (temp.size() == nums.size() / 2)
            {
                int subsetSum = 0;
                for (int x : temp)
                    subsetSum += x;

                // Compute other subset's sum
                int otherSum = totalSum - subsetSum;
                int diff = abs(otherSum - subsetSum);

                // Update global minimum difference
                minDiff = min(minDiff, diff);
            }
            return;
        }

        // pick current element
        temp.push_back(nums[ind]);
        f(ind - 1, nums, temp);

        // not pick current element
        temp.pop_back();
        f(ind - 1, nums, temp);
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        totalSum = 0;
        for (int x : nums)
            totalSum += x;

        minDiff = INT_MAX;
        vector<int> temp;
        f(nums.size() - 1, nums, temp);

        return minDiff;
    }
};
// This is a very basic recursive solution which will give TLE
