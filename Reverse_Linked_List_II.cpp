class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy, *cur = head;
        for(int i = 1; i < m; i++){
            pre = cur;
            cur = cur->next;
        }

        ListNode *p1,*p2;
        if(cur)
            p1 = cur->next;
        if(p1)
            p2 = p1->next;
        for(int j = m; j < n; j++){
            p1->next = cur;
            cur = p1;
            p1 = p2;
            if(p2) p2 = p2->next;
        }
        pre->next->next = p1;
        pre->next = cur;

        return dummy->next;
    }
};
http://www.cnblogs.com/4everlove/archive/2014/04/07/3651002.html
