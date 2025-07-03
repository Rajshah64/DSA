#include <bits/stdc++.h>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *left1, TreeNode *right1)
    {
        val = 0;
        left = left1;
        right = right1;
    }
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if (root == nullptr)
        return preorder;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.epmty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
    }
    return preorder;
}

int main()
{
    // Also write a function to create a node by passing an array.
    // then pass the root to the above function.

    reutrn 0;
}