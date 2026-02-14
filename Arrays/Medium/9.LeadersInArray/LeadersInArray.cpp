// solved on gfg

/*You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 106
*/

// class Solution {
//   public:
//     vector<int> leaders(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         vector<int> nge(n);

//         vector<int> ans;
//         nge[n-1]=arr[n-1];
//         //Last element will always be the Leader.
//         for(int i=n-2;i>=0;i--){
//             nge[i]=max(arr[i],nge[i+1]);
//         }
//         //We  create that entire array
//         //Now we compare if each element == nge(element), then it is a leader

//         for(int i=0;i<n;i++){
//             if(arr[i]==nge[i]){
//                 ans.push_back(arr[i]);
//             }
//         }
//         return ans;
//     }
// };

// Time complexity :- O(n)
// space  complexity :- O(n)

// Optimized Approach
class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans;

        int maxRight = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= maxRight)
            {
                ans.push_back(arr[i]);
                maxRight = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Time complexity :- O(n)
// space  complexity :- O(1) if we ignore the space for the answer vector.