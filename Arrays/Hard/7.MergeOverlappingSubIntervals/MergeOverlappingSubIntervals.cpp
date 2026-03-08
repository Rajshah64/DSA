// Leetcode Question 56. Merge Intervals

/*
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

// Approach 1
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int j = 0;
        // j is the pointer for the last element.
        sort(intervals.begin(), intervals.end()); // nlogn time
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        // as we are inserting one element , j=0.
        cout << ans[0][0] << " " << ans[0][1] << " " << endl;
        for (int i = 1; i < n; i++)
        { // n time
            cout << i << endl;
            int last_limit = ans[j][1];
            if (last_limit >= intervals[i][0] && last_limit <= intervals[i][1])
            {
                ans[j][1] = intervals[i][1];
            }
            else if (intervals[i][0] <= last_limit && intervals[i][1] <= last_limit)
            {
                // as both the limit of the next interval is same we dont do anything .
                continue;
            }
            else
            {
                ans.push_back(intervals[i]);
                // only when new element is added to the ans vector , j will be increased
                j++;
            }
        }
        return ans;
    }
};
// Time Complexity:- O(n) + O(nlogn)
// Space Complexity:- O(1) as we are only making 2 variables that is j and last_limit

// Approach 2
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {

            if (intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
// Time Complexity:- O(nlogn)
// Space Complexity:- O(1)