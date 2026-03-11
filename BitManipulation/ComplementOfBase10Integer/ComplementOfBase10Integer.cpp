// Leetcode Question 1009. Complement of Base 10 Integer

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;
        int k = log2(n) + 1;
        int mask = (1 << k) - 1;
        return mask - n;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)

//This question is same as Leetcode qquestion 476. Number Complement