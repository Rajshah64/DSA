// Leetcode Question 152: Maximum Product Subarray

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int mx = nums[0];
//         for(int i = 0; i < n; i++){
//             int product = 1;

//             for(int j = i; j < n; j++){
//                 product *= nums[j];
//                 mx = max(mx, product);
//             }
//         }
//         return mx;
//     }
// };
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//        int n=nums.size();
//        int maxprod=nums[0];
//        int minprod=nums[0];
//        int ansprod=nums[0];

//        for(int i=1;i<n;i++){
//             int temp=maxprod;

//             maxprod=max(max(nums[i],nums[i]*maxprod),nums[i]*minprod);
//             minprod=min(min(nums[i],nums[i]*temp),nums[i]*minprod);

//             ansprod=max(ansprod,maxprod);
//         }
//         return ansprod;
//     }
// };
// //Time Complexity:- O(n)
// //Space Complexity:- O(1)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int ans = -200;

        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)