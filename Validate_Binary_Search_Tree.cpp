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
    bool isValidBST(TreeNode* root) {
        
        return helper(root, false, false, 0, 0);
        
    }  
private:
    bool helper(TreeNode* root, bool left, bool right, int lmax, int rmin)  
    {  
    
      if(root==NULL)
      {
          return true;
      }
      
      if((left!=NULL && root->val>=lmax)||(right!=NULL &&root->val<=rmin))
      {
          return false;
      }
     
      return helper(root->left, true, right, root->val, rmin) && helper(root->right, left, true, lmax, root->val);
       
    }
};
