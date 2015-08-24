#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        int h=getDepth(root);
        vector<vector<int> > wholeTree(h);
        DFS(wholeTree, root, 0);

        vector<int> res;
        res.push_back(root->val);
        for(int i=1; i<h; i++)
        {
            int j=wholeTree[i].size()-1;
            res.push_back(wholeTree[i][j]);
        }

        return res;

    }
    void DFS(vector<vector<int>>& wholeTree, TreeNode* root, int level)
    {
        if(root==NULL) return;
        wholeTree[level].push_back(root->val);
        DFS(wholeTree, root->left, level+1);
        DFS(wholeTree, root->right, level+1);
    }
    int getDepth(TreeNode* root)
    {
        if(root==NULL) return 0;

        int l=getDepth(root->left);
        int r=getDepth(root->right);

        if(l<r)
        {
            return r+1;
        }
        else
        {
            return l+1;
        }
    }
};

int main()
{
    TreeNode* n1=new TreeNode(1);
    TreeNode* n2=new TreeNode(2);
    TreeNode* n3=new TreeNode(3);
    TreeNode* n4=new TreeNode(4);
    TreeNode* n5=new TreeNode(5);


    n1->left=n2;
    n1->right=n3;
    n2->left=NULL;
    n2->right=n5;
    n3->left=NULL;
    n3->right=n4;
    Solution s;

    vector<int> res=s.rightSideView(n1);
   

    for(auto ite1=res.begin(); ite1!=res.end(); ite1++)
    {
       cout<<*ite1<<endl;
    }
    return 0;
}
