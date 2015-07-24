class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL||p==NULL||q==NULL)
        {
            return NULL;
        }
        
        if(p->val<root->val&&q->val<root->val)
        {
           return lowestCommonAncestor(root->left, p, q);
        }
       
        
        else if(p->val>root->val&&q->val>root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    
        else if((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val<root->val)||p==root||q==root)
        {
            return root;
        }
        
       
    }
};
