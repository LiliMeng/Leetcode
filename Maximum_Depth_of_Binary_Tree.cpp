#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution{
public:
    int num;
    int maxDepth(TreeNode* root){

        if(root==NULL)
        {
            return 0;
        }

        num = numeric_limits<int>::min();
        travel(root,1);
        return num;
    }

    void travel(TreeNode* node, int level) {

        if(!node->left && !node->right){
            num=max(num,level);
            return ;
        }

        if(node->left){
            travel(node->left,level+1);
        }

        if(node->right){
            travel(node->right,level+1);
        }
    }
};

int main(){

    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(1);
    root->left=node1;
    root->right=node2;

    TreeNode* node3=new TreeNode(4);

    node1->left=node3;

    Solution s;
    cout<<s.maxDepth(root)<<endl;
    return 0;
}
