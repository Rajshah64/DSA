// Leetcode Question 128

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0) return 0;
//         sort(nums.begin(),nums.end());
//         int maxLen=1;
//         int currLen=1;
//         for(int i=1;i<n;i++){
//             if(nums[i]==nums[i-1]){
//                 continue;
//             }
//             else if(nums[i]==nums[i-1]+1){
//                 currLen++;
//             }else{
//                 maxLen=max(maxLen, currLen);
//                 currLen=1;
//             }
//         }
//         maxLen=max(maxLen, currLen);
//         return maxLen;
//     }
// };
// Time Complexity:- O(nlogn) for sorting + O(n) for traversing
// Space Complexity:- O(1)

// another approach
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for (int num : nums)
        {
            st.insert(num);
        }

        int maxLen = 1;
        for (int it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                // this means that if the curr element is not a starting element , we skip it .
                //  Here the condition is true if its the starting element
                int currNum = it;
                int currLen = 1;

                while (st.find(currNum + 1) != st.end())
                {
                    // this condition means that if we find it+1, then increase the length and the currNum and keep the loop going
                    currNum++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
// time complexity:- O(n) for traversing
// Space complexity:- O(n) for set
