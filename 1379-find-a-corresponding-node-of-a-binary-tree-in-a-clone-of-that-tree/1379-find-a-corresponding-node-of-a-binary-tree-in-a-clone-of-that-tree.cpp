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
    private:
        void preorder(TreeNode* clone, TreeNode* target, TreeNode* &result) {
            if(!clone) return;

            if(clone->val == target->val) {
                result = clone;
                return;
            }

            preorder(clone->left, target, result);
            preorder(clone->right, target, result);

            return;
        }
    
    public:
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
            TreeNode* result = NULL;
            preorder(cloned, target, result);
            return result;
        }
};