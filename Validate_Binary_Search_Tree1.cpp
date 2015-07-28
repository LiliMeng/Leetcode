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
        
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool helper(TreeNode* root, long minV, long maxV)
    {
        if(root==NULL) return true;
        
        if(root->val<=minV||root->val>=maxV)
        {
            return false;
        }
        
        return helper(root->left, minV, root->val)&&helper(root->right, root->val, maxV);
    }
};

或者
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool helper(TreeNode* root, long minV, long maxV)
    {
        if(root==NULL) return true;
        
        if(root->val>minV&&root->val<maxV)
        {
            return helper(root->left, minV, root->val)&&helper(root->right, root->val, maxV);
        }
        else
        {
            return false;
        }
    }
};
