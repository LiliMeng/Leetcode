class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* tmp=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                while(slow->next!=NULL&&tmp->next!=NULL)
                {
                    if(slow==tmp)
                    {
                        return slow;
                    }
                    else
                    {
                        slow=slow->next;
                        tmp=tmp->next;
                    }
                }
            }
        }
        
        return NULL;
    }
    
};
