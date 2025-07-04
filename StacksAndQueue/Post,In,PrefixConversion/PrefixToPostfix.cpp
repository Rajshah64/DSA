#include <bits/stdc++.h>

class solution
{
public:
    string Postfix2Prefix(string s)
    {
        int i = s.size() - 1;
        stack<string> st;
        while (i >= 0)
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

                st.push(t1 + t2 + s[i]);
            }
            i--;
        }
        return st.top();
    }
};

// Time complexity will be O(2N) and the same for space complexity.