// solved on gfg

class Solution
{
public:
    int findSum(int n)
    {
        // code here
        if (n < 1)
        {
            return 0;
        }
        return n + findSum(n - 1);
    }
};
