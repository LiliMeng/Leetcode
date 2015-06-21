class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
        {
            return false;
        }
        return DFS(sum,0,root);
    }
    
    bool DFS(int sum, int tmpsum, TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }
        
        tmpsum=tmpsum+root->val;
        
        if(root->left==NULL&&root->right==NULL)
        {
            if(tmpsum==sum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool l=DFS(sum,tmpsum,root->left);
        bool r=DFS(sum,tmpsum,root->right);
        
        return l||r;
      
    }
};
