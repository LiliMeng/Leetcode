#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> values;
        if(root==NULL)
        {
            return values;
        }
        vector<int> curr;
        DFS(values,curr,0,sum,root);
        return values;
    }

    void DFS(vector<vector<int>>& values, vector<int> curr, int tmpsum, int sum,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }

        tmpsum=tmpsum+root->val;
        curr.push_back(root->val);

        if(root->left==NULL&&root->right==NULL)
        {
            if(tmpsum==sum)
            {
                values.push_back(curr);
                return;
            }
        }

        DFS(values,curr,tmpsum,sum,root->left);
        DFS(values,curr,tmpsum,sum,root->right);
    }
};

int main(){

    TreeNode* node1=new TreeNode(5);
    TreeNode* node2=new TreeNode(4);
    TreeNode* node3=new TreeNode(8);
    TreeNode* node4=new TreeNode(11);
    TreeNode* node5=new TreeNode(13);
    TreeNode* node6=new TreeNode(4);
    TreeNode* node7=new TreeNode(7);
    TreeNode* node8=new TreeNode(2);
    TreeNode* node9=new TreeNode(1);
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node4->left=node7;
    node4->right=node8;
    node3->left=node5;
    node3->right=node6;
    node6->right=node9;
    Solution s;

    vector<vector<int>> v=s.pathSum(node1,22);

    for(auto ite=v.begin();ite!=v.end();ite++)
    {
        vector<int> v1=*ite;

        for(auto ite2=v1.begin();ite2!=v1.end();ite++)
        {
            cout<<*ite2<<endl;
        }

        cout<<"********************"<<endl;
    }

    return 0;
}
