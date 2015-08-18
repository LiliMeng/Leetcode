//这个假设如果在一个树上只能找到p, 找不到q时 就返回p, 而不是返回null, 只有在一棵树上既找不到p 又找不到q时 才返回null

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL||p==root||q==root) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        
        if(left==NULL&&right!=NULL)
        {
            return right;
        }
        else if(left!=NULL&&right==NULL)
        {
            return left;
        }
        else if(left!=NULL&&right!=NULL)
        {
            return root;
        }
        
    }
};
