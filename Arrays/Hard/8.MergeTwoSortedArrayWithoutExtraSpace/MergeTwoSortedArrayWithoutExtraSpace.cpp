// Leetcode Question 88. Merge Sorted Array

// Brute Force Solution
//  Create a new array to store the merged result and then copy it back to nums1
//  Time Complexity:- O(m + n) for merging and O(m + n) for copying back to nums1
//  Space Complexity:- O(m + n) for the temporary array
//  This is not what is expected as the problem states that we should not use extra space

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

// Optimized Solution
// Solution: Merge from the end of the array to avoid overwriting elements in nums1
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
// Time Complexity:-O(m+n)
// Space Complexity:- O(1)

// Note:- The optimized solution is the most efficient way to merge two sorted arrays without using extra space.
// It takes advantage of the fact that the merged array will be sorted, allowing us to fill it from the end without overwriting any elements in nums1.
// There is also another method called the "Gap Method" which is a more complex approach that can be used to merge two sorted arrays without extra space.
// but it is less efficient than the optimized solution provided above.
// Will solve it during revision time cause its very complex to understand and implement in the first go.