#include <bits/stdc++.h>

class solution
{
public:
    string Postfix2Infix(string s)
    {
        int i = 0;
        stack<string> st;
        while (i < s.size())
        {
            if (isalpha())
            {
                st.push(s[i]);
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string temp = '(' + t1 + s[i] + t2 + ')';
                st.push(temp);
            }
            i++;
        }
        return st.top();
    }
};

// Time complexity will be O(N) and the same for space complexity.