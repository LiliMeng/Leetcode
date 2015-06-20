#include<iostream>
#include<vector>


using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head,NULL);
    }

    TreeNode* build(ListNode* start, ListNode* end)
    {
        if(start==end)
        {
            return NULL;
        }

        ListNode* slow=start;
        ListNode* fast=start;

        while(fast!=end&&fast->next!=end)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        TreeNode* node=new TreeNode(slow->val);
        node->left=build(start,slow);
        node->right=build(slow->next,end);

        return node;

    }
};

int main(){

    Solution s;
    ListNode* head;
    head=new ListNode(1);
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(3);
    ListNode* node3=new ListNode(4);
    ListNode* node4=new ListNode(5);
    ListNode* node5=new ListNode(6);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    TreeNode* t=s.sortedListToBST(head);
    cout<<t->val<<endl;
    return 0;
}
