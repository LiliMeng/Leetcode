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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int> > result1, result2;
        
        vector<int> level;
        
        if(root==NULL)
        {
            return result1;
        }
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        int visitedCount=0, currentCount=1, nextCount=0;

        while(Q.size()!=0)
        {
            TreeNode* currentNode=Q.front();
            level.push_back(currentNode->val);
            Q.pop();
            visitedCount++;
            
            if(currentNode->left!=NULL)
            {
                Q.push(currentNode->left);
                nextCount++;
            }
            
            if(currentNode->right!=NULL)
            {
                Q.push(currentNode->right);
                nextCount++;
            }
            
            if(visitedCount==currentCount)
            {
                visitedCount=0;
                currentCount=nextCount;
                nextCount=0;
                result1.push_back(level);
                level.clear();
            }
            
           
        }
        
         for(int i=result1.size()-1; i>=0; i--)
        {
                result2.push_back(result1[i]);
        }
        
        return result2;
        
    }
};
