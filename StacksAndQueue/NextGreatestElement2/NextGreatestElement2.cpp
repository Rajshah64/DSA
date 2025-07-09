#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> st;
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
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
    while (!st.empty() && st.top() <= nums[n - 1])
    {
        st.pop();
    }
    if (st.empty())
    {
        ans[n - 1] = -1;
    }
    else
    {
        ans[n - 1] = st.top();
    }
    st.push(nums[n - 1]);

    return ans;
}

int main()
{
    // vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> res;
    res = nextGreaterElement(nums2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}