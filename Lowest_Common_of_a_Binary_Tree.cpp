//这个假设如果在一个树上只能找到p, 找不到q时 就返回p, 而不是返回null, 只有在一棵树上既找不到p 又找不到q时 才返回null
/*这个assumption是假设如果一棵树上只找到了一个p 而找不到q 也返回p 而不是NULL是么?

如果这样就好理解了~~ 在p,q分别在左右两棵树时,  left=lowestCommonAncestor(root->left, p, q); left为p 而不是null, 因为在这时左树只有p 不存在q
right=lowestCommonAncestor(root->right, p, q);  right就是q

或者p,q在右左两棵树情况一样 这样left!=NULL&&right!=NULL 就返回root为lowest common ancestor. 
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        if(root==NULL||p==root||q==root) {return root;}
        
        TreeNode* l=lowestCommonAncestor(root->left, p, q);
        TreeNode* r=lowestCommonAncestor(root->right, p, q);
        
        if(l!=NULL&&r!=NULL)
        {
            return root;
        }
        else if(l!=NULL&&r==NULL)
        {
            return l;
        }
        else if(l==NULL&&r!=NULL)
        {
            return r;
        }
    }
};
