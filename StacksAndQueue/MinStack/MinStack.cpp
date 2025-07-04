class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        pair<int, int> x;
        x.first = val;
        if (st.empty())
        {
            x.second = val;
        }
        else
        {
            if (x.first < st.top().second)
            {
                x.second = val;
            }
            else
            {
                x.second = st.top().second;
            }
        }
        st.push(x);
    }

    void pop()
    {
        // pair<int,int> ans=st.top();
        st.pop();
        // return ans.first;
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// This is not optimisized as it stores a pair in stack that means double the storage.

// 2*val - prev_mini = newVal;
// Use this formula which will replace the old min value and insert this in stack .
//

class MinStack
{
public:
    stack<long long> st;
    long long minVal;

    MinStack()
    {
        minVal = INT_MAX;
    }

    void push(int val)
    {
        long long x = val;
        if (st.empty())
        {
            minVal = x;
            st.push(x);
        }
        else
        {
            if (x >= minVal)
            {
                st.push(x);
            }
            else
            {
                st.push(2 * x - minVal);
                minVal = x;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        if (topVal < minVal)
        {
            minVal = 2 * minVal - topVal;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long topVal = st.top();
        if (topVal < minVal)
        {
            return (int)minVal;
        }
        return (int)topVal;
    }

    int getMin()
    {
        return (int)minVal;
    }
};
