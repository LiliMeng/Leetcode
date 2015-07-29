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
    ListNode* reverseList(ListNode* head) {
       
        ListNode* prev=NULL;
        ListNode* current=head;
        
        while(current!=NULL)
        {
            ListNode* temp=current->next; 
            current->next=prev;  //把每次current指针指到的都放在prev的前面
            prev=current;  //prev是当前的current  把current放在prev之前 然后再更新prev成为old current
            current=temp;  //current指针在不断前进一直走到链表最后
        }
        return prev;
    }
};

NULL 1, 2, 3,4 第一次 prev=NULL, current=1 
1,NULL,2,3,4, 第二次 prev=1, current=2 
2,1，NULL,3,4; prev=2, current=3
3,2,1,NULL,4   prev=3, current=4
4,3,2,1,NULL   prev=4 current=NULL 结束循环 不再进行下一次

//http://articles.leetcode.com/2010/04/reversing-linked-list-iteratively-and.html
