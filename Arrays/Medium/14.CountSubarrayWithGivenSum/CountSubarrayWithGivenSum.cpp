// Leetcode Question 560

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        unordered_map<int, int> mp; // store the sum-k , cnt(this cnt means how many times did a subarray of value k occured till that point.)
        int sum = 0;
        mp[0] = 1; // We have to initially put this cause if we need 2 and get 2 we need something to fall back on .
        for (int num : nums)
        {
            sum += num;
            int need = sum - k;
            if (mp.find(need) != mp.end())
            {
                cnt += mp[need];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
// Time Complexity:- O(n)
// Space complexity:- O(n) in worst case when all the elements are different and we have to store all the sums in the map.