// Leetcode question 283: Move Zeros to End

class Solution
{
private:
    void swap(int &a, int &b)
    {
        int t = b;
        b = a;
        a = t;
    }

public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                if (i != k)
                {
                    swap(nums[i], nums[k]);
                }
                k++;
            }
        }
    }
};
