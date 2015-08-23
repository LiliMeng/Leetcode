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

//搞两个指针，start和end end是最后一个不一样的值 比如 1->1->1->1  最初start指向第一个1之前的prev, end指向第一个1 
//start->next->val==end->next->val这样end就不断往后移动,直到end是第四个1(最后一个一样的)  如果start->next==end 这样就是链表
//1->2->3 没有执行内while循环这种, start和end指针各向后移动一个  如果是 1->1->1->1->2这种情况 start->next=end->next跳过这四个1

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
