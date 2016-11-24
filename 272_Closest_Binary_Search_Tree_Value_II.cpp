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
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        vector<int> result;
        
        inorder(root, target, k, result);
        
        return result;
    }


private:
    void inorder(TreeNode* root, double target, int k, vector<int>& result)
    {
        if(root==NULL)
        {
            return;
        }
        
        inorder(root->left, target, k, result);
        
        if(result.size()<k)
        {
            result.push_back(root->val);
        }
        else if(abs(root->val-target)<abs(result[0]-target))
        {
              // BST inorder is sorted array,
            // if we have dis(root->val) < dis(result[0]) and root->val > result[0], 
            // we can guarantee all elements [1...k-1] are closer than result[0].
            result.erase(result.begin());
            result.push_back(root->val);
        }
        
        inorder(root->right, target, k, result);
        
    }
   
    
        
};
