// Solved on gfg

// Brute Force Approach
//  class Solution {
//    public:
//      long subarrayXor(vector<int> &arr, int k) {
//          // code here
//          int n=arr.size();
//          long cnt =0;
//          for(int i=0;i<n;i++){
//              int xorSum=0;
//              for(int j=i;j<n;j++){
//                  xorSum^= arr[j];
//                  if(xorSum==k){
//                      cnt++;
//                  }
//              }
//          }
//          return cnt;
//      }
//  };
//  Time Complexity: O(N^2)
//  Space Complexity: O(1)

// Optimal Approach
class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        long cnt = 0;
        unordered_map<int, int> mp;
        int prefixXor = 0;
        for (int i = 0; i < n; i++)
        {
            prefixXor ^= arr[i];
            if (prefixXor == k)
            {
                cnt++;
            }
            int target = prefixXor ^ k;
            if (mp.find(target) != mp.end())
            {
                cnt += mp[target];
            }
            mp[prefixXor]++;
        }
        return cnt;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)

// Rathofy this approach . this is very similar to number of subarrays with given sum. we are using prefixXor and a map to store the frequency of prefixXor. we are checking if prefixXor is equal to k then we are incrementing the count. then we are calculating the target by XORing prefixXor with k and checking if target is present in the map then we are adding the frequency of target to the count. finally we are incrementing the frequency of prefixXor in the map.