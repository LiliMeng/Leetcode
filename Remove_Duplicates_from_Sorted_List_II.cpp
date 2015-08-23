class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummyHead = new ListNode(INT_MIN);  
        dummyHead->next = head;  
        ListNode* prev = dummyHead;  
        ListNode* curr = head;  
        while(curr!=NULL)  
        {  
            while(curr->next!=NULL && prev->next->val==curr->next->val)  
            {  
                curr = curr->next;  
            }  
            if(prev->next==curr)  
            {  
                prev = prev->next;  
            }  
            else  
            {  
                prev->next = curr->next;  
            }  
            curr = curr->next;  
    }  
      
    return dummyHead->next;  
    
    }
};
