#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL),right(NULL),next(NULL){}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if(root==NULL)
        {
            return;
        }

        TreeLinkNode* p=root;
        TreeLinkNode* first=NULL;

        while(p!=NULL)
        {
            if(first==NULL)
            {
                first=p->left;
            }

            if(p->left!=NULL)
            {
                p->left->next=p->right;
                p->right->next=NULL;
            }
            else
            {
                break;
            }

            if(p->next==NULL)
            {
                p=first;
                first=NULL;
            }
            else
            {
                p->right->next=p->next->left;
                p=p->next;

            }
        }

    }
};

int main(){

    Solution s;
    TreeLinkNode* root=new TreeLinkNode(3);
    TreeLinkNode* node1=new TreeLinkNode(1);
    TreeLinkNode* node2=new TreeLinkNode(2);
    root->left=node1;
    root->right=node2;

    s.connect(root);

    return 0;
}
