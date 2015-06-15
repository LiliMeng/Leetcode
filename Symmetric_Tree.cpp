#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if(root==NULL)
        {
            return true;
        }

        return helper(root->left,root->right);
    }

    bool helper(TreeNode* left, TreeNode* right)
    {
        if(left==NULL&&right==NULL)
        {
            return true;
        }
        else if(left==NULL||right==NULL)
        {
            return false;
        }

        bool cond1 = left->val==right->val;
        bool cond2 = helper(left->left,right->right);
        bool cond3 = helper(left->right, right->left);

        return cond1&&cond2&&cond3;
    }

};

int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(1);
    root->left=node1;
    root->right=node2;
    cout<<s.isSymmetric(root)<<endl;

    return 0;

}
