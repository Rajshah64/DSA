// Leetcode Question 1

// Brute Force Approach
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++)
//         {
//             int x = nums[i];
//             int rem = target - x;
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (nums[j] == rem)
//                 {
//                     return {i, j};
//                 }
//             }
//         }
//         return {-1, -1};
//     }
// };
// Time complexity:- O(N^2)
// Space complexity:- O(1)

// Optimised Approach
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<long long, int> mp;
        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];
            // This is the remainder we have to search in the map.
            if (mp.find(rem) != mp.end())
            {
                // You found the pair
                return {mp[rem], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// Time Complexity:O(n)
// Space Complexity:O(n)