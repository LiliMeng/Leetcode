#include<iostream>
#include<list>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* p = head;
        int len = 1;
        //(1) 计算链表长度
        while(p->next != NULL)
        {
            len++;
            p = p->next;
        }

        //(2) 让链表头尾相连
        p->next = head;

        //(3) 找到结果链表的尾节点
        k %= len;
        int step = len - k;
        while(step > 0)
        {
            p = p->next;
            step--;
        }

        //(4) 断开链表，从结果链表的尾节点位置 新的头结点，是结果链表尾节点的下一个结点。结果链表尾节点->next 置NULL
        head = p->next;
        p->next = NULL;

        return head;
    }
};

int main()
{
    ListNode* n1=new ListNode(1);
    ListNode* n2=new ListNode(2);
    ListNode* n3=new ListNode(3);
    ListNode* n4=new ListNode(4);
    ListNode* n5=new ListNode(5);
    ListNode* n6=new ListNode(6);
    ListNode*  n7=new ListNode(7);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;

    Solution s;
    ListNode* newHead=s.rotateRight(n1,3);
    while(newHead!=NULL)
    {
       cout<<newHead->val<<endl;
       newHead=newHead->next;
    }
    return 0;
}
