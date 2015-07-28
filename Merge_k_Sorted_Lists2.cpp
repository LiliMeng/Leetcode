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
    struct compare{
        bool operator()(ListNode* node1, ListNode* node2) const {
            return node1->val>node2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode* > &lists){
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* dummyHead=new ListNode(0);
        ListNode* p=dummyHead;
        
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=NULL)
            {
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty())
        {
            p->next=pq.top();
            p=p->next;
            pq.pop();
            if(p->next!=NULL)
            {
                pq.push(p->next);
            }
        }
        
        return dummyHead->next;
    }
    
};
