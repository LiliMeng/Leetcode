class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
        int sum=0;
        vector<int> res;
        if(root==NULL) return sum;
        int curr=root->val;
        DFS(res,root,curr);

        for(int i=0; i<res.size();i++)
        {
            sum=sum+res[i];
        }
        return sum;
    }

    void DFS(vector<int> &res, TreeNode* root, int curr)
    {
        if(root->left==NULL&&root->right==NULL) res.push_back(curr);

        if(root->left!=NULL)
        {
            DFS(res, root->left, curr*10+root->left->val);
        }

        if(root->right!=NULL)
        {
            DFS(res, root->right, curr*10+root->right->val);
        }
    }
};
