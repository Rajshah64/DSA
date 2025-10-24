// Leetcode question 583

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        // so the logic I can think of is that
        // we find the lcs and then subtract with each word and add it .
        // lets see

        // once I ran this all given test cases passed but the answer was wrong when I submitted .
        // rather than longest common substring we will use sub sequence.
        // after that we just subtract the size of lcs from both strings and add them.
        // so even if the other word is the lcs we will be left with the other characters only.
        vector<int> prev(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
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
        int result = (n - prev[m]) + (m - prev[m]);
        return result;
    }
};