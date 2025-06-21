#include <bits/stdc++.h>
// #include <iostream>
// #include <map>
// we can have an array of size 10^6 inside the main function
// and we can have an array of size 10^7 globally
using namespace std;

// int main()
// {
//     // This code only takes into account the lowercase.
//     // In case of Uppercase and other characters and numbers, take hash[256] which can store all characters
//     string s;
//     cout << "Enter your string: ";
//     cin >> s;
//     int hash[26] = {0};
//     int n;
//     cout << "Enter how many character you want to know the frequency about: ";
//     cin >> n;
//     char arr[n];
//     cout << "enter the characters: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < s.size(); i++)
//     {
//         hash[s[i] - 'a']++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << hash[arr[i] - 'a'] << endl;
//     }
//     return 0;
// }

// This time we will use the map stl to make it optimized;
// Map takes log(N) time in all cases(both string and int).
// int main()
// {
//     int n;
//     cout << "Enter the number of terms in array: " << endl;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << endl;
//     }
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[arr[i]]++;
//     }
//     // map always store the key in sorted order.Below is the proof.
//     for (auto it : mpp)
//     {
//         cout << it.first << "-->" << it.second << endl;
//     }
//     int q;
//     cout << "Enter the number of queries: " << endl;
//     cin >> q;
//     while (q--)
//     {
//         int number;
//         cin >> number;
//         cout << "the freq is " << mpp[number] << endl;
//     }
//     return 0;
// }

// Unordered Map
// The advantage is that the best and average case of unodered map is O(1). The Worst case is O(n).
// In both map and Unordered map the n is no. of elements in map.
//Most of the time we have to use unordered map. The worst case is only possible when there are lot of collision.
//I map any data structure can be a key even a pair but in unodered map it cant be a pair and has to be an individual data structure
 int main()
 {
    int n;
    cout << "Enter the number of terms in array: " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    // map always store the key in sorted order.Below is the proof.
    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }
    int q;
    cout << "Enter the number of queries: " << endl;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        cout << "the freq is " << mpp[number] << endl;
    }
    return 0;
}
