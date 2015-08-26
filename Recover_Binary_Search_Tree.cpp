#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int > vals;
        InOrderTravel(root, list, vals);
        sort(vals.begin(), vals.end());
        for(int i =0; i< list.size(); i++)
        {
                list[i]->val = vals[i];
        }
    }
    void InOrderTravel(TreeNode* node, vector<TreeNode*>& list, vector<int>& vals)
    {
        if(node == NULL) return;
        InOrderTravel(node->left, list, vals);
        list.push_back(node);
        vals.push_back(node->val);
        InOrderTravel(node->right, list, vals);
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

    n4->left=n2;
    n4->right=n6;
    n2->left=n1;
    n2->right=n7;
    n6->left=n5;
    n6->right=n3;

    Solution s;
    s.recoverTree(n4);

    cout<<n2->right->val<<endl;
    cout<<n6->right->val<<endl;

    return 0;
}
