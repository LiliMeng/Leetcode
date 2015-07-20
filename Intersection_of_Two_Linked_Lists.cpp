/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        
        int lenA=getLen(headA);
        int lenB=getLen(headB);
        
        if(lenA>lenB)
        {
            while(lenA>lenB)
            {
                headA=headA->next;
                lenA--;
            }
        }
        else
        {
            while(lenA<lenB)
            {
                headB=headB->next;
                lenB--;
            }
        }
       
       while(headA!=NULL)
       {
           if(headA==headB)
           {
               return headA;
           }
           
           headA=headA->next;
           headB=headB->next;
       }
       
       return NULL;
    
    }
    
    int getLen(ListNode* node)
    {
        int len=0;
        while(node!=NULL)
        {
            len++;
            node=node->next;
        }
        
        return len;
    }
   
   
};
