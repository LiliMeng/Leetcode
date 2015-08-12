class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    
      if(head==NULL)
      {
          return head;
      }
      
      ListNode* pre=head;
      ListNode* curr=head->next;
      
      while(curr!=NULL)
      {
          if(curr->val==pre->val)
          {
              pre->next=curr->next;
          }
          else
          {
              pre=curr;
          }
          
          curr=curr->next;
      }
      return head;
    }
};
