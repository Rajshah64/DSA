// Leetcode Question 268: Missing Number

// Most brute force approach I can think of is sorting the array and then checking the index with the number.
//  class Solution {
//  public:
//      int missingNumber(vector<int>& nums) {
//          sort(nums.begin(),nums.end());
//          int n=nums.size();
//          int ans=-1;
//          for(int i=0;i<n;i++){
//              if(nums[i]!=i){
//                  ans=i;
//                  break;
//                  //cout<<"ans is:-"<<ans<<endl;
//              }
//          }
//          if(ans==-1) return n;
//          return ans;
//      }
//  };
// Time Complexity:- Nlog(n) for sorting + N
// Space Complexity:- O(1)

// We can use a mathematical solution also
// sum of 0 to n is n*(n+1)/2

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (auto it : nums)
        {
            sum -= it;
        }
        return sum;
    }
};
// Time complexity:- O(N)
// Space Complexity:- O(1)