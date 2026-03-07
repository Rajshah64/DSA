// Solved on gfg

// Brute Force Approach
class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefixSum[i] == 0)
            {
                cnt = max(cnt, i + 1);
            }
            for (int j = i + 1; j < n; j++)
            {
                if (prefixSum[i] == prefixSum[j])
                {
                    cnt = max(cnt, j - i);
                }
            }
        }
        return cnt;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                cnt = max(cnt, i + 1);
            }
            if (mp.find(sum) != mp.end())
            {
                cnt = max(cnt, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return cnt;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(n)

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            // to remove the sum==0 case we add it in the map itself which will give us the answer .
            if (mp.find(sum) != mp.end())
            {
                cnt = max(cnt, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return cnt;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(n)

// KEY CONCEPT
prefixSum[j] - prefixSum[i] = target