class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL) return true;
        int n=getLength(head);
        
        ListNode* newhead=head;
        
        if(n%2==1)
        {
            int m=0;
            while(m<n/2)
            {
                 newhead=newhead->next;
                 m++;
            }
            
            ListNode* mid=reverseLinkedList(newhead->next);
            
            while(mid!=NULL)
            {
                if(head->val!=mid->val)
                {
                    return false;
                }
                mid=mid->next;
                head=head->next;
            }
        }
        else
        {
            int m=0;
            while(m<n/2)
            {
                 newhead=newhead->next;
                m++;
            }
            
            ListNode* mid=reverseLinkedList(newhead);
            
            while(mid!=NULL)
            {
            
                if(head->val!=mid->val)
                {
                return false;
                }
                mid=mid->next;
                head=head->next;
            }
        }
        
    }
    
    int getLength(ListNode* node)
    {
        int n=0;
        while(node!=NULL)
        {
            n++;
            node=node->next;
        }
        return n;
    }
    
    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* current=head;
        
        while(current!=NULL)
        {
            ListNode* temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
    
        return prev;
    }
};
