/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> myStack;
    TreeNode* current;
    
    BSTIterator(TreeNode *root) {
        while(!myStack.empty())
        {
            myStack.pop();
        }
        
        current=root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
     return (current!=NULL || !myStack.empty());   
    }

    /** @return the next smallest number */
    int next() {
        while(current!=NULL)
        {
            myStack.push(current);
            current=current->left;
        }
        
        current=myStack.top();
        myStack.pop();
        TreeNode* nxt = current;
        current= current->right;
        return nxt->val;
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
