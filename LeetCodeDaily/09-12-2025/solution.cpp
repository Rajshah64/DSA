// Leetcode question 3583

// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         const int MOD = 1e9 + 7;
//         int n = nums.size();

//         // nums[i] ≤ 1e5, so 2 * nums[i] ≤ 2e5
//         vector<long long> leftFreq(200001, 0);
//         vector<long long> rightFreq(200001, 0);

//         // fill rightFreq with all numbers
//         for (int x : nums) rightFreq[x]++;

//         long long ans = 0;

//         for (int j = 0; j < n; j++) {
//             int val = nums[j];

//             // remove nums[j] from right side (since j is now the middle index)
//             rightFreq[val]--;

//             int doubleVal = val * 2;

//             if (doubleVal <= 200000) {
//                 long long leftCount = leftFreq[doubleVal];
//                 long long rightCount = rightFreq[doubleVal];

//                 ans = (ans + (leftCount * rightCount) % MOD) % MOD;
//             }

//             // add nums[j] to leftFreq for future j
//             leftFreq[val]++;
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> rightFreq;
        for (int x : nums)
            rightFreq[x]++;

        unordered_map<int, int> leftFreq;
        long long ans = 0;

        for (int val : nums)
        {
            // j is current middle -> remove it from right side
            rightFreq[val]--;

            int doubled = val * 2;                     // target value for i and k
            long long leftCount = leftFreq[doubled];   // i < j with nums[i] == 2*nums[j]
            long long rightCount = rightFreq[doubled]; // k > j with nums[k] == 2*nums[j]

            ans = (ans + leftCount * rightCount) % MOD;

            // now move current val to left side for future j
            leftFreq[val]++;
        }

        return (int)ans;
    }
};
