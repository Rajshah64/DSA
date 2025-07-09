#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans(nums2.size());
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
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
        st.push(nums2[i]);
    }
    vector<int> ans2;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                ans2.push_back(ans[j]); // now using correct index
                break;                  // optional, since match found
            }
        }
    }
    // This takes a lot of time O(n^2).This can be solved by using a unordered map to store the value rather than ans. then directly map it which will take O(n) times.
    return ans2;
}

int main()
{
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> res;
    res = nextGreaterElement(nums1, nums2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}