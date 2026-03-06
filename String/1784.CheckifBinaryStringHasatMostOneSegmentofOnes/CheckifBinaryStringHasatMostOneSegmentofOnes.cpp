// Leetcoede Question 1784. Check if Binary String Has at Most One Segment of Ones

// Optimal Solution
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int n = s.size();
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                flag = 0;
            }
            if (s[i] == '1' && flag == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)


