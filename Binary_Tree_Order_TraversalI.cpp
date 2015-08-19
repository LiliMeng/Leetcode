class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       
       int h=getHeight(root);
       vector<vector<int>> res(h);
       DFS(res, root, 0);
       return res;
    }
    
    void DFS(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if(root==NULL) return;
        
        res[level].push_back(root->val);
        DFS(res, root->left, level+1);
        DFS(res, root->right, level+1);
    }
    
    int getHeight(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=getHeight(root->left);
        int r=getHeight(root->right);
        
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
