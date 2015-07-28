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
    bool isValidBST(TreeNode* root) {
       return valid(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool valid(TreeNode* node, int minVal, int maxVal) {
        if(node==NULL) {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return valid(node->left, minVal, node->val) &&
        valid(node->right, node->val, maxVal);
    }
};
