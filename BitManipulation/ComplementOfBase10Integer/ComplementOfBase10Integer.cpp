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

// This question is same as Leetcode qquestion 476. Number Complement

// class Solution {
// public:
//     int findComplement(int num) {
//         if(num==0) return 1;
//         // Here k is the number of bits required to represent num.
//         // So we do log2 and add 1 cause the indexing starts from zero.
//         // log2(10)~ 3 +1=4 bits required to represent the number
//         int k = log2(num)+1;
//         long long mask = ((1LL<<k) -1);
//         return mask -num;
//     }
// };

// Also we can directly do n^((1LL<<k)-1)
//  This means we are xor the original number with the mask
// Here mask is a number which has all set bits upto k bits. So when we do xor with the original number, it will flip all the bits of the original number and give us the complement.