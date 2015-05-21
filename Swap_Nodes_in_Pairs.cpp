#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head){

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next=head;
    ListNode* current=head;
    ListNode* prev=dummyHead;

    while(current!=NULL&&current->next!=NULL)
    {
        ListNode* current_next=current->next;                     //hold the previous node and current_next_next, and swap current and current_next
        ListNode* current_next_next=current_next->next;

        prev->next=current_next;
        current_next->next=current;
        current->next=current_next_next;

        prev=current;
        current=current_next_next;
    }

    return dummyHead->next;
    }
};

int main()
{
    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2);
    ListNode* n3=new ListNode(3);
    ListNode* n4=new ListNode(4);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;

    Solution s;
    ListNode* result=s.swapPairs(n1);
    while(result!=NULL)
    {
        cout<<result->val<<endl;
        result=result->next;
    }
    return 0;
}
