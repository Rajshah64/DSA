// Leetcode question 283: Move Zeros to End


// brute force method
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> temp;
//         for(int i=0;i<n;i++){
//             if(nums[i]!=0){
//                 temp.push_back(nums[i]);
//             }
//         }
//         //now directly put it in the array
//         for(int i=0;i<temp.size();i++){
//             nums[i]=temp[i];
//         }
//         //now the remaining elements of the array should be zeros.
//         for(int i=temp.size();i<n;i++){
//             nums[i]=0;
//         }
//     }
// };
// Time complexity:- O(n)
// Space Complexity:-O(n)

class Solution
{
private:
    void swap(int &a, int &b)
    {
        int t = b;
        b = a;
        a = t;
    }

public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        // int k = 0;

        // for (int i = 0; i < n; i++) {
        //     if (nums[i] != 0) {
        //         if (i != k) {
        //             swap(nums[i], nums[k]);
        //         }
        //         k++;
        //     }
        // }

        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;
        for (int i = j + 1; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
// Time complexity:- O(n)
// Space complexity:- O(1)