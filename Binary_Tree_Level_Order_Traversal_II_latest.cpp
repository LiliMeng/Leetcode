class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        vector<int> level;
        
        TreeNode* last=root;
        q.push(root);
        
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            level.push_back(root->val);
            if(root->left!=NULL) q.push(root->left);
            if(root->right!=NULL) q.push(root->right);
            
            if(root==last)
            {
                last=q.back();
                res.insert(res.begin(),level);
                level.clear();
            }
        }
        return res;
    }
};
