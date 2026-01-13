// Leetcode Question 268: Missing Number

//Most brute force approach I can think of is sorting the array and then checking the index with the number. 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int ans=-1;
//         for(int i=0;i<n;i++){
//             if(nums[i]!=i){
//                 ans=i;
//                 break;
//                 //cout<<"ans is:-"<<ans<<endl;
//             }
//         }
//         if(ans==-1) return n; 
//         return ans;  
//     }
// };
//Time Complexity:- Nlog(n) for sorting + N
//Space Complexity:- O(1)

//We can use a mathematical solution also 
//sum of 0 to n is n*(n+1)/2

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         int sum=n*(n+1)/2;
//         for(auto it:nums){
//             sum-=it;
//         }
//         return sum;
//     }
// };
//Time complexity:- O(N)
//Space Complexity:- O(1)



//Another great appraoch for the same is using bit manipulation using XOR
// as we have to find the missing number between 0 and n. 
// What we can do is use the property that is a^a=0.
// What we do is first XOR 0 to n . 
// i.e missingVal= (0^1^2^...^n).
// Then we XOR with all the values in the array . lets take n=3
// missingVal= (0^1^2^3) ^ (3^0^1) = 2 as all other becomes zero and anything xor with 0 is that number itself. 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int missingVal= 0;
        for(int i=1;i<=n;i++) missingVal^=i;
        for(auto it: nums) missingVal^=it;
        return missingVal;
    }
};
//Time complexity:- O(N)
//Space Complexity:- O(1)