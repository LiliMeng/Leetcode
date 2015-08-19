class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        int depth=getHeight(root);
        vector<vector<int>> res(depth);
        if(depth==0)
        {
            return res;
        }
        DFS(res, root, 0);
    }
    
    void DFS(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if(root==NULL)
        {
            return;
        }
        res[level].push_back(root->val);
        DFS(res,root->left, level+1);
        DFS(res,root->right, level+1);
    }

    int getHeight(TreeNode* root)
    {
        if(root==NULL) return 0;
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        if(left>right)
        {
            return left+1;
        }
        else
        {
            return right+1;
        }
        
    }
};
