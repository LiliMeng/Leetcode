class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
       ListNode* slow1=head;
       ListNode* slow2=hasCycle(head);

        if(hasCycle(head)==NULL)
        {
            return NULL;
        }
        else
        {
            while(slow1->next!=NULL&&slow2->next!=NULL)
           {
                if(slow1==slow2)
                {
                    return slow1;
                }
                
                slow1=slow1->next;
                slow2=slow2->next;
            }
        }


    }

    ListNode* hasCycle(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return false;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                return slow;
            }
        }

        return NULL;
    }

};
