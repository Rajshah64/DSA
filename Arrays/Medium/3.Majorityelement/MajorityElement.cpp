// Leetcode Question 169 : Majority Element

// Brute Force approach
//  create a map and store the freq
//  then traverse the map and find the max
//  class Solution {
//  public:
//      int majorityElement(vector<int>& nums) {
//          int n=nums.size();
//          unordered_map<int,int> mp;
//          for(auto i: nums){
//              if(mp.find(i)!=mp.end()){
//                  mp[i]++;
//              }else{
//                  mp[i]=1;
//              }
//          }
//          //We created a map containing all elements with their freq
//          int maximum=0;
//          int result =-1;
//          for(auto it: mp ){
//              if(it.second> maximum){
//                  maximum=it.second;
//                  result=it.first;
//              }
//          }
//          return result;
//      }
//  };
// Time Complexity:- O(2N) as we are traversing both map and the vector
// Space Complexity:- O(N) as we are using unodered map

// Better Approach
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];
//     }
// };
// Time Complexity:- O(nlogn)
// Space Complexity:- O(1)

// Boyer Moore Voting Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)