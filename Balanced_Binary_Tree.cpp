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
    bool isBalanced(TreeNode* root) {
     
     if(findDepth(root)==-1)
     {
         return false;
     }
     else
     {
         return true;
     }
    }
    int findDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int depthLeft=findDepth(root->left);
        
        int depthRight=findDepth(root->right);
        
        if(root->left==NULL&&root->right!=NULL)
        {
            return -1;
        }
        
        if(root->left!=NULL&&root->right==NULL)
        {
            return -1;
        }
        
        if(abs(depthLeft-depthRight)>1)
        {
            return -1;
        }
        
        return max(depthLeft, depthRight)+1;
    }
        
};
