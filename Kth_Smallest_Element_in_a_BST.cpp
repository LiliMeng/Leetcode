class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    
        if(k==1 && root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        
        int left=count(root->left);
        if(left>=k)
        {
            return kthSmallest(root->left,k);
        }
        else if(left+1==k)
        {
            return root->val;
        }
        else if(left+1<k)
        {
            return kthSmallest(root->right, k-left-1);
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
