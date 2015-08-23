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

//也可以只用一个指针

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            while(curr->next!=NULL&&curr->val==curr->next->val)
            {
                curr->next=curr->next->next;
            }
            
            curr=curr->next;
        }
        
        return head;
    }
};
