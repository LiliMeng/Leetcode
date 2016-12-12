/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        stack<TreeNode*> myStack;
        
        bool b = false;
        
        TreeNode* current = root;
        
        while(current!=NULL ||!myStack.empty())
        {
            while(current!=NULL)
            {
                myStack.push(current);
                current = current->left;
            }
            
            current = myStack.top();
            myStack.pop();
            
            if(b)
            {
                return current;
            }
            if(current==p)
            {
                b = true;
            }
            
            current=current->right;
        }
      
        return NULL;
    }
};
