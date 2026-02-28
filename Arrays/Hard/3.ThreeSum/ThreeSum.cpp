// Leetcode Question 15

// Brute Force Approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// time Complexity:- O(n^3) for loops and O(log n) for sorting the triplet and O(n) for inserting in set.
// space Complexity:- O(n) for set and O(n) for answer vector.

// Better Approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            set<int> hashset;
            for (int j = i + 1; j < n; j++)
            {
                int rem = -(nums[i] + nums[j]);
                if (hashset.find(rem) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// time Complexity:- O(n^2) for loops and O(log n) for sorting the triplet and O(n) for inserting in set.
//  space Complexity:- O(n) for set and O(n) for answer vector.

// Optimal Approach
//  Two Pointer Approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // first sort the array
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};
// Time Complexity:- O(n^2) for loops and O(n log n) for sorting the array.
// Space Complexity:- O(n) for answer vector and O(1) for two pointers.