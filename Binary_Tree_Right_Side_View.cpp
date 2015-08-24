class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        
        if(root==NULL) return res;
        
        int h=getDepth(root);
        vector<vector<int> > wholeTree(h);
        DFS(wholeTree, root, 0);

        res.push_back(root->val);
        for(int i=1; i<h; i++)
        {
            int j=wholeTree[i].size()-1;
            res.push_back(wholeTree[i][j]);
        }

        return res;

    }
    void DFS(vector<vector<int>>& wholeTree, TreeNode* root, int level)
    {
        if(root==NULL) return;
        wholeTree[level].push_back(root->val);
        DFS(wholeTree, root->left, level+1);
        DFS(wholeTree, root->right, level+1);
    }
    int getDepth(TreeNode* root)
    {
        if(root==NULL) return 0;

        int l=getDepth(root->left);
        int r=getDepth(root->right);

        if(l<r)
        {
            return r+1;
        }
        else
        {
            return l+1;
        }
    }
};
