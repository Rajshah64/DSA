// Leetcode question 90

// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n=nums.size();
//         int ran= 1<<n;
//         set<vector<int>> st;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<ran;i++){
//             vector<int> temp;
//             for(int j=0;j<n;j++){
//                 if(i & (1<<j)){
//                     temp.push_back(nums[j]);
//                 }
//             }
//             st.insert(temp);
//         }
//         vector<vector<int>> ans (st.begin(),st.end());
//         return ans;
//     }
// };

class Solution
{
private:
    void subset(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp)
    {
        ans.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            subset(i + 1, nums, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subset(0, nums, ans, temp);
        return ans;
    }
};