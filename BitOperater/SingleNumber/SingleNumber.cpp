// Leetcode 136

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/


class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int XOR = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            XOR = XOR ^ nums[i];
        }
        return XOR;
    }
};

//The brute force method is that we take an unordered map and then store the frequency of each of the elements. 
//Then we iterate through the map and return the element which has a frequency of 1.
//But that takes more time and also more space . 
