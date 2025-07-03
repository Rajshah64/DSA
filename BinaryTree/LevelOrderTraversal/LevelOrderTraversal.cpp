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
}

vector<vector<int>>
levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        reutrn ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    // Also write a function to create a node by passing an array.
    // then pass the root to the above function.

    reutrn 0;
}