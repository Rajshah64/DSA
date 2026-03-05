// Leetcode Question 1758

// class Solution {
// public:
//     int minOperations(string s) {
//         int cnt1 =0;
//         int cnt2 =0;
//         string t= s;
//         if(t[0]=='1'){cnt1++;t[0]='0';}
//         //This case is for checking if the first char is zero.
//         for(int i=1;i<s.size();i++){
//            if(t[i]==t[i-1]){
//                 t[i]= (t[i]=='0')? '1': '0';
//                 cnt1++;
//            }
//         }

//         if(s[0]=='0'){cnt2++;s[0]='1';}
//         //This case is for checking if the fist char is one .
//         for(int i=1;i<s.size();i++){
//            if(s[i]==s[i-1]){
//                 s[i]= (s[i]=='0')? '1': '0';
//                 cnt2++;
//            }
//         }
//         return min(cnt1,cnt2);
//     }
// };
// Time Complexity:- O(2n)
// Space Complexity:- O(n)

// Optimal Approach
class Solution
{
public:
    int minOperations(string s)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0 && s[i] == '0')
            {
                cnt2++;
            }
            if (i % 2 == 1 && s[i] == '0')
            {
                cnt1++;
            }
            if (i % 2 == 0 && s[i] == '1')
            {
                cnt1++;
            }
            if (i % 2 == 1 && s[i] == '1')
            {
                cnt2++;
            }
        }
        return min(cnt1, cnt2);
    }
};
// Time Complexity:- O(n)
// space Complexity:- O(1)