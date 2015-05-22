#include<iostream>
#include<vector>

using namespace std;



struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){

        if(head==NULL) return head;

        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* prev=dummyHead;


        while(prev->next!=NULL)
        {
            if(prev->next->val==val)
            {
                prev->next=prev->next->next;

            }
            else
            {
                prev=prev->next;

            }
        }
        return dummyHead->next;
    }
};

int main(){

    ListNode* n1=new ListNode(4);
    ListNode* n2=new ListNode(4);
    ListNode* n3=new ListNode(3);
    ListNode* n4=new ListNode(4);
    ListNode* n5=new ListNode(4);
    ListNode* n6=new ListNode(4);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;

    Solution s;
    ListNode* result=s.removeElements(n1,4);
    while(result!=NULL)
    {
        cout<<result->val<<endl;
        result=result->next;
    }
    return 0;

}
