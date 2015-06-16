#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> values;
        if(root==NULL)
        {
            return values;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty())
        {
            TreeNode* n=nodes.top();
            values.push_back(n->val);

            nodes.pop();

            if(n->right)
            {
                nodes.push(n->right);
            }
            if(n->left)
            {
                nodes.push(n->left);
            }
        }
        return values;
    }
};

int main(){

    Solution s;
    TreeNode* root=new TreeNode(3);
    TreeNode* node1=new TreeNode(1);
    TreeNode* node2=new TreeNode(2);
    root->left=node1;
    root->right=node2;

    vector<int> preorderT=s.preorderTraversal(root);

    for(auto ite=preorderT.begin();ite!=preorderT.end();ite++)
    {
        cout<<*ite<<endl;
    }
    return 0;
}
