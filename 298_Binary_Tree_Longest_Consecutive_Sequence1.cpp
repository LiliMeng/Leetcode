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
    int longestConsecutive(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int res=0;
        
        dfs(root, root->val-1, 0, res);
        
        return res;
    }
    
    void dfs(TreeNode* root, int value, int conseqDepth, int &res)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->val==value+1)
        {
            conseqDepth++;
        }
        else
        {
            conseqDepth=1;
        }
        
        res=max(res, conseqDepth);
        
        dfs(root->left, root->val, conseqDepth, res);
        dfs(root->right, root->val, conseqDepth, res);
    }
};
