/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int result;
public:
    int traverse(TreeNode* root) {
        if(!root) return 0;
        
        int lTree = traverse(root->left);
        int rTree = traverse(root->right);
        
        result += abs(lTree - rTree);
        
        return root->val + lTree + rTree;
        
    }
    int findTilt(TreeNode* root) {
        traverse(root);
        
        return result;
    }
};