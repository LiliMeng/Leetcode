/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if(root==NULL) return result;

        queue<TreeNode* > Q;
        Q.push(root);

        int nextLevelCount=0, currentLevelCount=1;
        vector<int> level;
        int visitedCount=0;

        //push every level of the tree into the result continuously as long as there is a TreeNode in the queue
        while(Q.size()!=0)
        {
            TreeNode* newRoot = Q.front();    //Update the new root continuously by pushing the TreeNode* into and out of the queue
            level.push_back(newRoot->val);
            visitedCount++;
            Q.pop();    //pop out of the current root

            if(newRoot->left!=NULL)
            {
                Q.push(newRoot->left);
                nextLevelCount++;
            }
            if(newRoot->right!=NULL)
            {
                Q.push(newRoot->right);
                nextLevelCount++;
            }
            if(visitedCount==currentLevelCount)
            {
                visitedCount=0;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
                result.push_back(level);
                level.clear();
            }

        }
         return result;
}
};
