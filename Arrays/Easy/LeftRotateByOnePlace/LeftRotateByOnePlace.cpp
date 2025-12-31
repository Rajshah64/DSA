// Leetcode Question 189: Rotate Array

class Solution
{
public:
    void rotate(vector<int> &a, int d)
    {
        int n = a.size();
        d = d % n;
        // This is done so if we have to rotate the same size as a's length that is rotating 0 times, so we skip.
        vector<int> temp;

        for (int i = n - 1; i >= n - d; i--)
        {
            temp.push_back(a[i]);
        }
        // step1:- take d elements from the end and store it in a vector.

        // step2:- shift each element from the start by d position in the right.
        for (int i = n - d - 1; i >= 0; i--)
        {
            a[i + d] = a[i];
        }

        // step3:- insert the stores element in the front of the array.
        for (int i = 0; i < d; i++)
        {
            a[i] = temp[d - i - 1];
        }
    }
};