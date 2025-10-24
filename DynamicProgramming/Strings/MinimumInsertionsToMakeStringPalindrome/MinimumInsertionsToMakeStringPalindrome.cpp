// Leetcode question 1312

// The logic is
// If we know the longest palindromic sub-sequence is x and the length of the string is n then,
//  what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.

// most optimized solution
class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<int> prev(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        int ans = n - prev[n];
        return ans;
    }
};