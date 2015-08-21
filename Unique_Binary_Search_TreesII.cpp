class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> vs;
        if(start>end)
        {
            vs.push_back(NULL);
            return vs;
        }
        
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*> l=generate(start, i-1);
            vector<TreeNode*> r=generate(i+1, end);
            
            for(int j=0; j<l.size(); j++)
            {
                for(int k=0; k<r.size(); k++)
                {
                    TreeNode* n=new TreeNode(i);
                    n->left=l[j];
                    n->right=r[k];
                    vs.push_back(n);
                }
            }
        }
        return vs;
    }
};
