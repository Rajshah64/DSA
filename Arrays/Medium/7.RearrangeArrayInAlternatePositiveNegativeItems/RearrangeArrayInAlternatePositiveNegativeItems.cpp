// Leetcode Question 2149

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n=nums.size();
//         //Take two vector of half the size of original vector
//         vector<int> pos;
//         vector<int> neg;
//         for(int num : nums){
//             if(num>=0){
//                pos.push_back(num);
//             }
//             else{
//                 neg.push_back(num);
//             }
//         }
//         vector<int> ans;
//         int i=0,j=0;
//         while(i<n/2 && j<n/2){
//             ans.push_back(pos[i]);
//             ans.push_back(neg[j]);
//             i++;
//             j++;

//         }
//         return ans;
//     }
// };
// Time Complexity:- O(n/2) for the while loop and O(n) for the nums.
// Space Complexity:- O(2n)

// Optimized approach
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0;
        int neg = 1;
        for (int num : nums)
        {
            if (num >= 0)
            {
                ans[pos] = num;
                pos += 2;
            }
            else
            {
                ans[neg] = num;
                neg += 2;
            }
        }
        return ans;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(n)