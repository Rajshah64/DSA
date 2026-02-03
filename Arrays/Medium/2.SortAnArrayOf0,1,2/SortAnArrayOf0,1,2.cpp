// Leetcoee Question 75 : Sort Colors

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };

// class Solution {
//     private:
//         void swap(int &a, int &b){
//             int temp=a;
//             a=b;
//             b=temp;
//         }
// public:
//     void sortColors(vector<int>& nums) {
//         int n=nums.size();
//         int i=0;
//         int j=n-1;
//         int mid=(i+j)/2;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (nums[j] > nums[j + 1])
//                     swap(nums[j], nums[j + 1]);
//             }
//         }

//     }
// };
// this is the brute force approach
// Time Complexity:- O(N^2)

// Better approach
// This is also called as counting method
//  class Solution {
//  public:
//      void sortColors(vector<int>& nums) {
//          int noOfZero=0;
//          int noOfOne=0;
//          int noOfTwo=0;
//          int n=nums.size();

//         for(int i=0;i<n;i++){
//             if(nums[i]==0){
//                 noOfZero++;
//             }
//             else if(nums[i]==1){
//                 noOfOne++;
//             }else{
//                 noOfTwo++;
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(noOfZero>0) {nums[i]=0;noOfZero--;}
//             else if(noOfOne >0) {nums[i]=1;noOfOne--;}
//             else nums[i]=2;noOfTwo--;
//         }

//     }
// };
// Time complexity:- O(2N)
// Space complexity:- O(1)

// Dutch Flag approach
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};
// Time Complexity:- O(n)
// Space Complexity:- O(1)
