// Leetcode question 229


// Brute force approach
//Brute force Approach 
// Use an unordered map and then just compare each elements freq with n/3 if so then return it.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,float> mp;
        for(int num : nums){
            mp[num]++;
        }
        float threshold=n/3;
        for(auto it: mp){
            int key=it.first;
            float value=it.second;
            cout<< "key:- "<<key<<"value:- "<<value<<endl;
            if(value > threshold){
                ans.push_back(key);
            }
        }
        return ans;
    }
};
// Time Complexity:- O(n) + O(n) = O(n)
// Space Complexity:- O(n) for the unordered map