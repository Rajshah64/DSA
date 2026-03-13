// Solved on gfg

// Brute Force Approach
//  class Solution {
//    public:
//      int inversionCount(vector<int> &arr) {
//          // Code Here
//          int n=arr.size();
//          int cnt= 0;
//          for(int i=0;i<n;i++){
//              for(int j=i+1;j<n;j++){
//                  if(arr[i]>arr[j]){
//                      cnt++;
//                  }
//              }
//          }
//          return cnt;
//      }
//  };
// Time Complexity:- O(n^2)
// Space Complexity:- O(1)

// Optimal Approach
// We use merge sort
// But while we go up the recursion tree that is after merging the left and right part
// We do cross checking with the left and right group and count the number of inversions
class Solution
{
private:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                cnt += (mid - left) + 1;
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

public:
    int inversionCount(vector<int> &arr)
    {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};
// Time Complexity:- O(nlog(n))
// Space Complexity:- O(1)