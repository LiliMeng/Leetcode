/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *  };
 **/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* tmp=root;
        if(root==NULL)
        {
            return NULL;
        }
        else
        {
            if(key==tmp->val)
            {    
                delete tmp;
                return tmp;
            }
            else if(key<tmp->val)
            {
                tmp=tmp->left;
                return deleteNode(tmp, key);
            }
            else 
            {
                tmp=tmp->right;
                return deleteNode(tmp, key);
            }
        }
    }
 
};
