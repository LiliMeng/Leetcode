/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> inorder;
    
    void traversal(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            traversal(root->left);
        }
        inorder.push_back(root->val);
        if(root->right!=NULL)
        {
            traversal(root->right);
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder.clear();
        
        traversal(root);
        
        return inorder;
        
    }
};
