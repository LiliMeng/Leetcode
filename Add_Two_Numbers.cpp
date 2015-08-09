class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead=new ListNode(0);
        ListNode* p1=l1, *p2=l2, *curr=dummyHead;
        
        int carry=0;
        
        while(p1!=NULL||p2!=NULL)
        {
            int x=(p1!=NULL)?p1->val:0;
            int y=(p2!=NULL)?p2->val:0;
            int digit=carry+x+y;
            carry = digit / 10;
            curr->next = new ListNode(digit % 10);
            curr=curr->next;
            if(p1!=NULL) p1=p1->next;
            if(p2!=NULL) p2=p2->next;
        }
        if(carry>0)
        curr->next=new ListNode(carry);
        
        return dummyHead->next;
    }
};
