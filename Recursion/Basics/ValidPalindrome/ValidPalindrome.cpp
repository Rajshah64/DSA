// leetcode question 125

#include <cctype>

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string temp="";
//         for(int i=0;i<=s.size();i++){
//                 char c=s[i];
//                 if(isalpha(c)||isdigit(c)){
//                     temp +=tolower(c);
//                 }
//         }
//         //cout << temp[]<< endl;
//         int left =0;
//         int right= temp.size()-1;
//         while(left<=right){
//             if(temp[left]!=temp[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

class Solution
{
private:
    bool f(int i, string &s)
    {
        if (i > s.size() / 2)
        {
            return true;
        }
        if (s[i] != s[s.size() - i - 1])
        {
            return false;
        }
        return f(i + 1, s);
    }

public:
    bool isPalindrome(string s)
    {
        string temp = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                temp += tolower(c);
            }
        }
        if (temp == "")
            return true;
        return f(0, temp);
    }
};