// Remember this method this is very important .

// This method is a bit time consuming .
// The better approach would be to take sum as a parameter and check if it is equal to k or not.
// and every time you call recursive function , at that time you can pass the updated sum.

#include <bits/stdc++.h>
using namespace std;

void findSubsequences(int curr, vector<int> &arr,
                      vector<int> &subarr, vector<vector<int>> &res)
{

    // Base case: When we reach the end of the array,
    // add the current subsequence to the result

    if (curr == arr.size())
    {
        int sum = 0;
        for (int i = 0; i < subarr.size(); i++)
        {
            sum += subarr[i];
        }
        if (sum == 2)
            res.push_back(subarr);
        return;
    }

    //  Include the current element in the subsequence
    subarr.push_back(arr[curr]);

    // Recurse to the next element
    findSubsequences(curr + 1, arr, subarr, res);

    // Backtrack: Remove the current element and explore
    // the next possibility
    subarr.pop_back();

    //  Do not include the current element
    // in the subsequence
    findSubsequences(curr + 1, arr, subarr, res);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int n = arr.size();

    vector<int> subarr;
    vector<vector<int>> res;

    findSubsequences(0, arr, subarr, res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// This method is if you want to print only one ans.
// How it works is if we find a valid subsequence, we immediately return true.
// Thus the other half of the recursive tree is never executed, thus is faster .
// Remember this method this is very important .

// #include <bits/stdc++.h>
// using namespace std;

// bool findSubsequences(int curr, vector<int> &arr,
//                       vector<int> &subarr, vector<vector<int>> &res)
// {

//     // Base case: When we reach the end of the array,
//     // add the current subsequence to the result

//     if (curr == arr.size())
//     {
//         int sum = 0;
//         for (int i = 0; i < subarr.size(); i++)
//         {
//             sum += subarr[i];
//         }
//         if (sum == 2)
//         {
//             res.push_back(subarr);
//             return true;
//         }
//         else
//             return false;
//     }

//     //  Include the current element in the subsequence
//     subarr.push_back(arr[curr]);

//     // Recurse to the next element
//     if (findSubsequences(curr + 1, arr, subarr, res))
//     {
//         return true;
//     }

//     // Backtrack: Remove the current element and explore
//     // the next possibility
//     subarr.pop_back();

//     //  Do not include the current element
//     // in the subsequence
//     if (findSubsequences(curr + 1, arr, subarr, res) == true)
//     {
//         return true;
//     }

//     return false;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 1};
//     int n = arr.size();

//     vector<int> subarr;
//     vector<vector<int>> res;

//     findSubsequences(0, arr, subarr, res);

//     for (int i = 0; i < res.size(); i++)
//     {
//         for (int j = 0; j < res[i].size(); j++)
//         {
//             cout << res[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
//}

#include <bits/stdc++.h>
using namespace std;

void findSubsequences(int curr, vector<int> &arr,
                      vector<int> &subarr, vector<vector<int>> &res, int sum, int s)
{

    // Base case: When we reach the end of the array,
    // add the current subsequence to the result

    if (curr == arr.size())
    {
        if (s == sum)
        {
            for (auto it : subarr)
                cout << it << " ";
            return true;
        }

        else
            return false;
    }

    //  Include the current element in the subsequence
    subarr.push_back(arr[curr]);
    s += arr[curr];
    // Recurse to the next element
    if (findSubsequences(curr + 1, arr, subarr, res, sum, s))
    {
        return true;
    }

    // Backtrack: Remove the current element and explore
    // the next possibility
    subarr.pop_back();
    s -= arr[curr];
    //  Do not include the current element
    // in the subsequence
    if (findSubsequences(curr + 1, arr, subarr, res, sum, s))
    {
        reutrn true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int n = arr.size();

    vector<int> subarr;
    vector<vector<int>> res;
    int sum = 2;
    // cin >> sum ;
    findSubsequences(0, arr, subarr, res, 0, sum);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// The next main concept is count subsequences.
/*
    the main structure will be
    f() {
        base case:
            return 1 -> condition is satisfied
            return 0 -> condition is not stisfied
        l=f()
        r=f()
        return l+r;
    }

*/

#include <bits/stdc++.h>
using namespace std;

int findSubsequences(int curr, vector<int> &arr,
                     vector<vector<int>> &res, int sum, int s)
{

    // this is another base case so as to save time .
    // If the current sum exceeds the target sum, we can stop exploring this path.
    // this only works for positive numbers
    if (s > sum)
    {
        return 0;
    }
    if (curr == arr.size())
    {
        if (s == sum)
        {
            return 1;
        }

        else
            return 0;
    }

    //  Include the current element in the subsequence

    s += arr[curr];
    // Recurse to the next element
    int l = findSubsequences(curr + 1, arr, subarr, res, sum, s);

    // Backtrack: Remove the current element and explore
    // the next possibility

    s -= arr[curr];
    //  Do not include the current element
    // in the subsequence

    int r = findSubsequences(curr + 1, arr, subarr, res, sum, s);
    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int n = arr.size();

    vector<int> subarr;
    vector<vector<int>> res;
    int sum = 2;
    // cin >> sum ;
    cout << findSubsequences(0, arr, subarr, res, 0, sum);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     for (int j = 0; j < res[i].size(); j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
