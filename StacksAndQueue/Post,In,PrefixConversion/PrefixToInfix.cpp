#include <bits/stdc++.h>

class solution
{
public:
    string Prefix2Infix(string s)
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

                st.push(s[i] + t2 + t1);
            }
            i++;
        }
        return st.top();
    }
};

// Time complexity will be O(N) and the same for space complexity.