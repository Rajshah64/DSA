// Leetcode Question 88. Merge Sorted Array

//Brute Force Solution
// Create a new array to store the merged result and then copy it back to nums1
// Time Complexity:- O(m + n) for merging and O(m + n) for copying back to nums1
// Space Complexity:- O(m + n) for the temporary array
// This is not what is expected as the problem states that we should not use extra space

// Better Solution
// Solution: Merge from the end of the array to avoid overwriting elements in nums1
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        if (n == 0)
        {
            return;
        }
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};
// Time Complexity:- O(nlogn) for sorting and O(n) for inserting nums2
// Space Complexity:- O(1)


//Optimal Solution
/