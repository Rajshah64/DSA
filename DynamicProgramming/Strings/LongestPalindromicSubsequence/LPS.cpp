// Leetcode question 516

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // the logic is that if we just reverse the string and then apply lcs
        //  we will get the longest common subsequeunce which will be a palindrome.
        string t = string(s.rbegin(), s.rend());
        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }
};