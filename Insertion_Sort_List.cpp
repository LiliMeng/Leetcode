#include<vector>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) { }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

      if(head==NULL||head->next==NULL) return head;

      ListNode* dummyHead=new ListNode(0);
      dummyHead->next=head;
      ListNode* current=head;

      while(current->next!=NULL)
      {
        ListNode* current_next=current->next;
        ListNode* pre=dummyHead;
        while(pre->next->val<=current_next->val&&pre->next!=current_next)
        {
            pre=pre->next;
        }

        ListNode* pre_next=pre->next;

        if(current->val>current_next->val)
        {
            current->next=current_next->next;
            pre->next=current_next;
            current_next->next=pre_next;
        }
        else
        {
            current=current_next;
        }

      }
      return dummyHead->next;
	}
};

int main()
{
    ListNode* n1= new ListNode(5);
    ListNode* n2= new ListNode(2);
    ListNode* n3= new ListNode(4);
    ListNode* n4= new ListNode(6);
    ListNode* n5= new ListNode(1);
    ListNode* n6= new ListNode(3);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;

    Solution s;
    ListNode* result=s.insertionSortList(n1);

    while(result!=NULL)
    {
        cout<<result->val<<endl;
        result=result->next;
    }

  return 0;
}
