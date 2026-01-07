// Leetcode question 26

// This is the brute force approach
// TC:- Nlog(N) + N
// SC:- O(N)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> st;
//         for(int i=0;i<nums.size();i++){
//             st.insert(nums[i]);
//         }
//         int ind=0;
//         for(auto it: st){
//             nums[ind]=it;
//             ind++;
//         }
//         return st.size();
//     }
// };

// Optimized approach
// TC:- O(N)
// SC:- O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        // this i is the pointer where the new element is present.
        // The most recent one.
        for (int j = 1; j < n; j++)
        {
            if (nums[j] != nums[i])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};