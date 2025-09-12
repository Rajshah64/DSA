// Leetcode question 46
// time complexity: O(n*n!)
// space complexity: O(n) + O(n!) for recursion stack space and answer array
// class Solution {
//     private:
//         void permutation(int ind, vector<int>& nums, vector<vector<int>>& ans){
//             if (ind == nums.size()) {
//             ans.push_back(nums);
//             return;
//             }
//             for (int i = ind; i < nums.size(); i++) {
//                 swap(nums[ind], nums[i]);
//                 permutation(ind + 1, nums, ans);
//                 swap(nums[ind], nums[i]);
//             }
//         }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         permutation(0,nums,ans);
//         return ans;
//     }
// };

// time complexity: O(n*n!)
// space complexity: O(n) + O(n) for recursion stack space and frequency array
class Solution
{
private:
    void permutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &freq)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                temp.push_back(nums[i]);
                freq[i] = 1;
                permutation(nums, ans, temp, freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(nums.size(), 0);
        permutation(nums, ans, temp, freq);
        return ans;
    }
};