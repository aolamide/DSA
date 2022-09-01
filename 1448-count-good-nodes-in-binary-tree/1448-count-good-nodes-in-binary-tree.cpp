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
public:
    int count = 1;
    void dfs(TreeNode* root, int maxSoFar) {
        if(!root) return;
        if(root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val;
        } 
        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        
        return count;
    }
};