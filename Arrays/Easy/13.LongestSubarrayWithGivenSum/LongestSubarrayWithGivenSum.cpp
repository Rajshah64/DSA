// Solved on GFG

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int maxLen = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int m = i; m <= j; m++)
                {
                    sum += arr[m];
                }
                if (sum == k)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
// Time Complexity : O(N^3)
// Space Complexity : O(1)
// this is the brute force approach
// we just check for all the subarrays and calculate their sum
// if the sum is equal to k we update the maxLen accordingly

// Optimized Approach using Hashing
// what we do is we keep a running sum and store the first occurrence of each running sum in a hashmap
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int maxLen = 0;
        int n = arr.size();
        unordered_map<long long, int> mp;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == k)
                maxLen = max(maxLen, i + 1);
            if (mp.find(sum - k) != mp.end())
                maxLen = max(maxLen, i - mp[sum - k]);
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)
// This version uses a hashmap to store the first occurrence of each running sum
// We iterate through the array once, updating the running sum and checking if (running sum - k) exists in the hashmap
// If it does, we update the maxLen accordingly
// This approach is for both positive and megative and also can contain zeros in the array
// This is the most optimal approach for this problem, which contains both positive and negative integers.

// We can optimize this only for positive integers using sliding window approach
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int maxLen = 0;
        int n = arr.size();
        int i = 0;
        long long sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += arr[j];

            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }

            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};