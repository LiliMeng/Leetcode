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
        res[level].push_back(root->val);  //第一次res[2].push_back(3); 
        DFS(res,root->left, level-1);     //root->left为9， 然后 res[1].push_back(9); 里面又有DFS(res, root->left->left, level-2), DFS(RES, root->left->right, level-2)均为NULL 因为9的左树右树均为NULL返回
        DFS(res, root->right, level-1);   //root->right为20， res[1].push_back(20); 这个函数里面又有
        //DFS(res, root->right->left, level-2) res[0]={15}, DFS(res, root->right->right, level-2) res[0]={15,7}再往下一层都是NULL 不再进行了
        
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
