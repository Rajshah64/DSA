// Leetcode question 229

// Brute force approach
// Brute force Approach
// Use an unordered map and then just compare each elements freq with n/3 if so then return it.
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, float> mp;
        for (int num : nums)
        {
            mp[num]++;
        }
        float threshold = n / 3;
        for (auto it : mp)
        {
            int key = it.first;
            float value = it.second;
            cout << "key:- " << key << "value:- " << value << endl;
            if (value > threshold)
            {
                ans.push_back(key);
            }
        }
        return ans;
    }
};
// Time Complexity:- O(n) + O(n) = O(n)
// Space Complexity:- O(n) for the unordered map

// Optimal Approach
// We can use the Boyer-Moore Voting Algorithm to find the majority elements
// We can have at most 2 majority elements in the array as we are looking for elements that appear more than n/3 times. So we can maintain two candidates and their counts. We can iterate through the array and update the candidates and their counts accordingly.
// Finally, we can check if the candidates are actually majority elements by counting their occurrences in the array.
// Optimal approach
// We use modified Moore voting method
// so the logic is how many char are present, there can be at max 2 element in a array which satisfies the condition.
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1)
            {
                cnt1++;
            }
            else if (nums[i] == el2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int mini = (int)n / 3 + 1;
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums)
        {
            if (num == el1)
            {
                cnt1++;
            }
            if (num == el2)
            {
                cnt2++;
            }
        }
        if (cnt1 >= mini)
        {
            ans.push_back(el1);
        }
        if (cnt2 >= mini)
        {
            ans.push_back(el2);
        }
        return ans;
    }
};
// Time Complexity:- O(n) + O(n) = O(n)
// Space Complexity:- O(1) as we are using constant space for the candidates and their counts.
