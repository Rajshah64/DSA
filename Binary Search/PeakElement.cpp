#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time. 

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
Constraints:
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

*/

int PeakElement(vector<int>& a) {
    int low = 1;
    int n = a.size();
    int high = n - 2;
    if (n == 1) { return 0; }
    if (a[0] > a[1]) { return 1; }
    if (a[n - 1] > a[n - 2]) { return n - 1; }
    while (low <= high) {
        int mid = (low+high) / 2;
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
            return mid;
        }
        if (a[high] > a[high - 1] && a[high] > a[high + 1]) {
            return high;
        }
        else if (a[low] > a[low - 1] && a[low] > a[low + 1]) {
            return low;
        }
        else {
            low++;
            high--;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = { 1,2,3,4,5,6,7,8,5,1 };
    cout << "The Peak element is: " << PeakElement(a) << endl;
    return 0;
}
