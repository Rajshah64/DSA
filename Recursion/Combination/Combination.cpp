// Combination Sum
// Time Complexity: O(2^n)* n
// Space Complexity: O(n) + O(k)  (k is the average length of each combination)
// Leetcode question 39

class Solution
{
private:
    void combsum(int k, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (k == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (candidates[k] <= target)
        {
            temp.push_back(candidates[k]);
            combsum(k, target - candidates[k], candidates, ans, temp);
            temp.pop_back();
        }

        combsum(k + 1, target, candidates, ans, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        combsum(0, target, candidates, ans, temp);
        return ans;
    }
};