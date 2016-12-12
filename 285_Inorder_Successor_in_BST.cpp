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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (b) return t;
            if (t == p) b = true;
            t = t->right;
        }
        return NULL;
    }
};
