#include <bits/stdc++.h>

class InfixToPostfix
{
public:
    int priority(char a)
    {
        if (a == '^')
            return 3;
        else if (a == '*' || a == '/')
            return 2;
        else if (a == '+' || a == '-')
            return 1;
        else
            return -1;
    }

    string InfixToPostfix(string s)
    {
        stack<char> st;
        string ans;
        for (auto i : s)
        {
            char c = s[i];
            if (isalnum(c))
            {
                ans += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
    }

    string InfixToPrefix(string s)
    {
        stack<char> st;
        for (auto i : s)
        {
            st.push(s[i]);
        }
        string newS;
        while (!st.empty())
        {
            if (st.top() == '(')
            {
                st.pop();
                newS += ')';
            }
            else if (st.top() == ')')
            {
                st.pop();
                newS += '(';
            }
            else
            {
                newS += st.top();
                st.pop()
            }
        }
        newS = InfixToPostfix(newS);
        s = '';
        while (!st.empty())
        {
            if (st.top() == '(')
            {
                st.pop();
                s += ')';
            }
            else if (st.top() == ')')
            {
                st.pop();
                s += '(';
            }
            else
            {
                s += st.top();
                st.pop()
            }
        }
        return s;
    }
};
