/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head,NULL);
    }
    
    TreeNode* build(ListNode* start, ListNode* end){
        
        if(start==end)
        {
            return NULL;
        }
        
        ListNode* slow=start;
        ListNode* fast=start;
        
        while(fast!=end&&fast->next!=end)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        TreeNode* node=new TreeNode(slow->val);
        node->left=build(start,slow);
        node->right=build(slow->next,end);
        
        return node;
        
    }
};
