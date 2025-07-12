#include <bits/stdc++.h>

using namespace std;

// int sumSubarrayMins(vector<int> &arr)
// {
//     int n = arr.size();
//     // int sum = (n * (2 + (n - 1))) / 2;
//     int ans = 0;
//     vector<int> min;
//     for (int i = 0; i < n; i++)
//     {
//         min.push_back(arr[i]);
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < min[min.size() - 1])
//             {
//                 min.push_back(arr[j]);
//             }
//             else
//             {
//                 min.push_back(arr[min.size() - 1]);
//             }
//         }
//     }
//     for (auto it : min)
//     {
//         ans += it;
//     }
//     return ans;
// }

/// The intuition is we need to know where the next smaller index and the previous smaller index is present.
// We then subtract with the index we are on to find its contribution in the sum .
// This ca not be thought in the interview we have to know it before hand .

stack<int> findNSE(vector<int> &arr)
{
}

stack<int> findPSE(vector<int> &arr)
{
}

int sumSubarrayMins(vector<int> &arr)
{
    stack<int> nse = findNSE(arr);
    stack<int> pse = findPSE(arr);
    int total = 0;
    int MOD = (int)(1e29 + 7);
    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;

        total = (total + (right * left * 1LL * arr[i])) % MOD;
    }
    return total;
}

int main()
{
    vector<int> hts = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = sumSubarrayMins(hts);
    cout << "the answer is : " << res << endl;
    return 0;
}