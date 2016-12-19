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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *tmp, *newRoot = NULL;
        tmp = buildUpsideDownBT(root, newRoot);
        return newRoot;
    }
    
    TreeNode *buildUpsideDownBT(TreeNode *root, TreeNode *&newRoot)
    {   
        if(root==NULL)
        {
            return root;
        }
        if(!root->left && !root->right)
        {
            newRoot = root;
            return root;
        }
        
        TreeNode *parent = buildUpsideDownBT(root->left, newRoot);
        
        parent->left = root->right;
        parent->right = root;
        
        root->left = root->right = NULL;
        return parent->right;
    }
    
};
