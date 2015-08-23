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

//搞两个指针，start和end end是最后一个不一样的值 比如 1->1->1->  最初start指向第一个1之前的prev, end指向第一个1 start->next->val==end->next->val这样end
//就不断往后移动,直到end是第四个1(最后一个一样的) 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;

        ListNode* start=dummyHead;
        ListNode* end=head;


        while(end!=NULL)
        {
            while(end->next!=NULL&&start->next->val==end->next->val)
            {
                end=end->next;
            }

            if(start->next==end)
            {
                start=start->next;
            }
            else
            {
                start->next=end->next;
            }

            end=end->next;
        }

        return dummyHead->next;
    }
};
