#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

//Breadth First Search

class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if(root==NULL) return result;

        queue<TreeNode* > Q;
        Q.push(root);

        int nextLevelCount=0, currentLevelCount=1;
        vector<int> level;
        int visitedCount=0;

        //push every level of the tree into the result continuously as long as there is a TreeNode in the queue
        while(Q.size()!=0)
        {
            TreeNode* newRoot = Q.front();    //Update the new root continuously by pushing the TreeNode* into and out of the queue
            level.push_back(newRoot->val);
            visitedCount++;
            Q.pop();    //pop out of the current root

            if(newRoot->left!=NULL)
            {
                Q.push(newRoot->left);
                nextLevelCount++;
            }
            if(newRoot->right!=NULL)
            {
                Q.push(newRoot->right);
                nextLevelCount++;
            }
            if(visitedCount==currentLevelCount)
            {
                visitedCount=0;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
                result.push_back(level);
                level.clear();
            }

        }
         return result;
}
};

int main()
{
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(7);

    n1->left=n2;
    n1->right=n3;
    n2->left=NULL;
    n2->right=NULL;
    n3->left=n4;
    n3->right=n5;

    n4->left=NULL;
    n4->right=NULL;

    n5->left=NULL;
    n5->right=NULL;

    Solution s;
    vector<vector<int> > LO;
    LO=s.levelOrder(n1);

    for(auto ite=LO.begin();ite!=LO.end();ite++)
    {
        auto a=*ite;
        for(auto i=a.begin();i!=a.end();i++)
        {
        cout<<*i<<endl;
        }
    }
    return 0;
}
