// Solved on maukri .com / coding ninjas .com

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // We start from the most bottom and then go up.
    // rule is that if s1[i-1]==s2[j-1], then we print and go i-1,j-1
    // if not than the max of left and above element.
    int val = dp[n][m];
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i = i - 1;
            j = j - 1;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    // cout<<ans<<endl;
    return ans;
}

/*
Longest Common Subsequence (LCS) - DP Matrix Visualization
Sample Input:
s1 = "ababa"  (n = 5)
s2 = "cbbcad" (m = 6)

Step 1: Initialize DP table (6 x 7), all zeros
dp[i][j] = length of LCS between s1[0..i-1] and s2[0..j-1]

       j->  0  1(c)  2(b)  3(b)  4(c)  5(a)  6(d)
i\      -------------------------------------------
0       | 0   0     0     0     0     0     0
1(a)    | 0   0     0     0     0     1     1
2(b)    | 0   0     1     1     1     1     1
3(a)    | 0   0     1     1     1     2     2
4(b)    | 0   0     1     2     2     2     2
5(a)    | 0   0     1     2     2     3     3

Step 2: Filling rules
- if(s1[i-1] == s2[j-1])
    dp[i][j] = 1 + dp[i-1][j-1]
- else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Step 3: Reconstruction of LCS
- Start from dp[n][m] = dp[5][6] = 3
- While i>0 && j>0:
    1. i=5,j=6: s1[4]='a', s2[5]='d' → not match → dp[i-1][j] >= dp[i][j-1] → move up (i--)
    2. i=4,j=6: s1[3]='b', s2[5]='d' → not match → move up (i--)
    3. i=3,j=6: s1[2]='a', s2[5]='d' → not match → move up (i--)
    4. i=2,j=6: s1[1]='b', s2[5]='d' → not match → move left (j--)
    5. i=2,j=5: s1[1]='b', s2[4]='a' → not match → move up (i--)
    6. i=1,j=5: s1[0]='a', s2[4]='a' → match → add 'a' to ans → ans="a" → move diagonal (i--, j--)
    7. Continue remaining matches similarly
- Final LCS = "bba"

Step 4: Notes
- Tie-breaker: When dp[i-1][j] == dp[i][j-1], prefer moving **up** (i--)
- Reverse the collected string at the end because reconstruction starts from the bottom-right.

Step 5: Time & Space Complexity
- Time: O(n*m)  → Fill all dp cells once
- Space: O(n*m) → Store the DP table
- Can optimize space to O(min(n,m)) if only LCS length is needed.
*/
