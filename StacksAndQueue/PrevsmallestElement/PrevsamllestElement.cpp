#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 5, 2, 10, 8};
    vector<int> res;
    res = nextGreaterElement(nums1);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}