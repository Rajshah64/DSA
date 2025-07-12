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
class Solution {
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
    int CeilBST(TreeNode* root, int key) {
        int ceil=INT_MAX; // Initialize ceil to -1, which indicates no ceil found
        if(!root){
            return -1; // If the tree is empty, return -1
        }

        //TreeNode* temp =root;
        while(root !=nullptr && root->val!=key){
            if(root->val==key){
                return key;
            }
            if(root->val < key){
                //ceil=root->val;
                root=root->right;
            }
            else{
                ceil>root->val? ceil=root->val:ceil=ceil; // Update ceil if current node's value is greater than key
                root=root->left;
            }
        }
        return ceil;
    }
};