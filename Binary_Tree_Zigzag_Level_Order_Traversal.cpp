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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        int h=getDepth(root);
        vector<vector<int> > wholeTree(h);
        vector<vector<int>> zigzagWholeTree(h);
        if(root==NULL)
        return zigzagWholeTree;
        DFS(wholeTree, root, 0);

        for(int i=0; i<h; i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<wholeTree[i].size(); j++)
                {
                    zigzagWholeTree[i].push_back(wholeTree[i][j]);
                }
            }
            else
            {
                for(int j=wholeTree[i].size()-1; j>=0; j--)
                {
                    zigzagWholeTree[i].push_back(wholeTree[i][j]);
                }
            }

         }

         return zigzagWholeTree;


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

        if(l>r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
};

int main()
{
    TreeNode* n1=new TreeNode(1);
    TreeNode* n2=new TreeNode(2);
    TreeNode* n3=new TreeNode(3);
    //TreeNode* n4=new TreeNode(15);
    //TreeNode* n5=new TreeNode(7);

    //TreeNode* n6=new TreeNode(1);
    //TreeNode* n7=new TreeNode(2);

    n1->left=n2;
    n1->right=n3;
    /*
    n2->left=n6;
    n2->right=n7;
    n3->left=n4;
    n3->right=n5;
    */
    Solution s;

    vector<vector<int>> res=s.zigzagLevelOrder(n1);

    for(auto ite1=res.begin(); ite1!=res.end(); ite1++)
    {
        vector<int> level=*ite1;
        for(auto ite2=level.begin(); ite2!=level.end(); ite2++)
        {
            cout<<*ite2<<endl;
        }

        cout<<"****************"<<endl;
    }




    return 0;
}
