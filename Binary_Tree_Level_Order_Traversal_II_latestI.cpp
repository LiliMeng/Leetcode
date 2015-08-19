class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int d=getDepth(root);
        vector<vector<int>> res(d);
        DFS(res,root,d-1);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if(root==NULL)
        {
            return;
        }
        res[level].push_back(root->val);
        DFS(res,root->left, level-1);
        DFS(res, root->right, level-1);
    }
    
    
    int getDepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=getDepth(root->left);
        int r=getDepth(root->right);
        
        if(l>r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
};
