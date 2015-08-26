#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        if(root==NULL) return res;
        DFS(res, root, to_string(root->val));
        return res;
    }

    void DFS(vector<string> &res, TreeNode* root, string curr)
    {
        if(root->left==NULL&&root->right==NULL) res.push_back(curr);

        if(root->left!=NULL)
        {
            DFS(res, root->left, curr+"->"+to_string(root->left->val));
        }

        if(root->right)
        {
            DFS(res, root->right, curr+"->"+to_string(root->right->val));
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
    TreeNode* n6=new TreeNode(6);
    TreeNode* n7=new TreeNode(7);


    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;

    n3->left=n6;
    n3->right=n7;

    Solution s;
    vector<string> res=s.binaryTreePaths(n1);
    //string res=s.binaryTreePaths(n1);

   // cout<<res<<endl;


    for(auto ite=res.begin(); ite!=res.end(); ite++)
    {
        cout<<*ite<<endl;
        cout<<"*****************"<<endl;
    }


    return 0;

}
