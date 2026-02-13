// Leetcode Question 53: Maximum Subarray

//Brute Force Approach 
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = nums[0];   

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];          
//                 maxi = max(maxi, sum);   
//             }
//         }
//         return maxi;
//     }
// };
//Time Complexity:- O(N^2)
//Space Complexity:- O(1)


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = nums[0];   
//         int i=0;
//         int j=i+1;
        
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];          
//                 maxi = max(maxi, sum);   
//             }
//         }
//         return maxi;
//     }
// };



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum= nums[0];
        int maxSum= nums[0];

        for(int i=1;i<n;i++){
            currSum= max(nums[i], currSum + nums[i]);
            maxSum= max(currSum, maxSum);
        }

        return maxSum;
    }
};

// Time Complexity:- O(n)
// Space Complexity:- O(1)