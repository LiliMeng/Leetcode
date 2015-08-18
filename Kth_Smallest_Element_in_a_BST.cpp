class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    
        if(k==1 && root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        
        int l=count(root->left);
        
        if(k<=l)
        {
            return kthSmallest(root->left,k);
        }
        else if(k==l+1)
        {
            return root->val;
        }
        else if(k>l+1)
        {
            return kthSmallest(root->right, k-l-1);
        }
    }
    
    int count(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            return count(root->left)+count(root->right)+1;
        }
    }
};
