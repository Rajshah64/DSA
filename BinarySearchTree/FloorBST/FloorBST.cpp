/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root ==nullptr){
    //         return root;
    //     }
    //     TreeNode* temp=root;
    //     if(temp->val>val){
    //         return searchBST(temp->left, val);
    //     }
    //     else if(temp->val<val){
    //         return searchBST(temp->right, val);
    //     }
    //     return temp;
    // }
    int FloorBST(TreeNode *root, int key)
    {
        int floor = -1; //
        while (root != nullptr)
        {
            if (root->val == key)
            {
                return key; // If the key is found, return it
            }
            if (root->val < key)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
    }
};