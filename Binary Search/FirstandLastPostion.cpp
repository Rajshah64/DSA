#include <iostream>
#include<vector>
#include<utility>

using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

pair<int,int> searchRange(vector<int>& a, int target) {
    int size = a.size();
    int lb = lower_bound(a.begin(), a.end(), target) - a.begin();
    int ub = (upper_bound(a.begin(), a.end(), target) - a.begin());
    cout << size << lb << ub << endl;
    if ((lb == size) || (a[lb] != target)) {
        return { -1,-1 };
    }
    return { lb,ub - 1 };
    

}

int main()
{
    vector<int> a = { 5,7,7,8,8,10 };
    pair<int, int >result;
    result = searchRange(a, 8);
    cout << "the range of 8 is " << result.first<<" "<<result.second << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
