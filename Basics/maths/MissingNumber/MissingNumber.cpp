//leetcode question 268

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sums= 0;
        int n=nums.size();
        for(auto i: nums){
            sums+=i;
        }
        return ((n*(n+1))/2)- sums;
    }
};