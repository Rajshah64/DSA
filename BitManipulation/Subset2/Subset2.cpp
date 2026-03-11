// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10




class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        int ran = 1 << n;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < ran; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(nums[j]);
                }
            }
            st.insert(temp);
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};