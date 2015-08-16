#include<iostream>
#include<vector>
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
    vector<TreeNode*> generateTrees(int n){

        return generate(1,n);
    }

    vector<TreeNode*> generate(int start, int stop)
    {
        vector<TreeNode*> vs;
        if(start > stop){
            vs.push_back(NULL);
            return vs;
        }

        for(int i=start; i<=stop; i++)
        {
            auto l=generate(start,i-1);
            auto r=generate(i+1,stop);

            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                TreeNode* n=new TreeNode(i);
                n->left=l[j];
                n->right=r[k];
                vs.push_back(n);
                }
            }
        }

        return vs;
    }

};

int main(){

    Solution s;

    vector<TreeNode*> gT;
    gT=s.generateTrees(3);

    for(auto ite=gT.begin();ite!=gT.end();ite++)
    {
        cout<<*ite<<endl;
    }

    return 0;

}
