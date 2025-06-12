#include <iostream>
#include<vector>

using namespace std;

/*

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

*/

int RotatedSortedArray(vector<int>& a, int target) {
    int low = 0;
    int high = a.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == a[mid]) { return mid; }
        // left sort
        else if (a[low] < a[mid]) {
            if (a[low] <= target && target < a[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        
        }
        //high sorted
        else {
            if (a[mid] < target && target <= a[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    
    return - 1;
}

bool SortedArray2(vector<int>& a, int target) {
    int low = 0;
    int high = a.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (target == a[mid]) { return true; }
        if (a[low] == a[mid] && a[mid] == a[high]) {
            low++;
            high--;
            continue;
        }
        //left sorted
        if (a[low] <= a[mid]) {
            if (a[low] <= target && target <= a[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        //high sorted
        else {
            if (a[mid] <= target && target <= a[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> a = { 1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1 };
    //int low = 4;
    //int high = 6;
    //cout << lower_bound(a.begin() + low, a.begin() + high, 0) - (a.begin() );
    bool result = SortedArray2(a,2);
    cout << "the position is : " << result << endl;
}
