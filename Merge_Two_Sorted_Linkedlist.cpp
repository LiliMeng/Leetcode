#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummyHead=new ListNode(0);  //dummyHead is fixed
        ListNode* p=dummyHead;  //p is the pointer of the newly merged linked list, to decide which one shall be the next node

        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }

        if(l1!=NULL&&l2==NULL) p->next=l1;
        if(l1==NULL&&l2!=NULL) p->next=l2;


        return dummyHead->next;
    }
};

int main()
{

    ListNode* n1= new ListNode(2);
    ListNode* n2= new ListNode(4);
    ListNode* n3= new ListNode(5);
    ListNode* n4= new ListNode(1);
    ListNode* n5= new ListNode(3);
    ListNode* n6= new ListNode(6);

    n1->next=n2;
    n2->next=n3;
    n3->next=NULL;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;

    Solution s;
    ListNode* result=s.mergeTwoLists(n1,n4);
    while(result!=NULL)
    {
        cout<<result->val<<endl;
        result=result->next;
    }

    return 0;
}
