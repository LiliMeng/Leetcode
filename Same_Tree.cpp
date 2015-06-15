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
    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p==NULL&&q==NULL)
        {
            return true;
        }
        else if(p==NULL||q==NULL)
        {
            return false;
        }

        if(p->val==q->val)
        {
            bool l=isSameTree(p->left,q->left);
            bool r=isSameTree(p->right,q->right);
            return l&&r;
        }
        else
        {
            return false;
        }

    }
};

int main(){

    Solution s;
    TreeNode* p=new TreeNode(3);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(1);
    p->left=node1;
    p->right=node2;

    TreeNode* q=new TreeNode(3);
    TreeNode* node3=new TreeNode(1);
    TreeNode* node4=new TreeNode(1);
    q->left=node3;
    q->right=node4;

    cout<<s.isSameTree(p,q)<<endl;

    return 0;

}



