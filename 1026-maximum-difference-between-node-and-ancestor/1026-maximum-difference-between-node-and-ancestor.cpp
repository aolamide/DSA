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
    int answer = 0;
    int dfs(TreeNode* root, int currMin, int currMax) {
        if(!root) {
            return currMax - currMin;
        }
        
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        
        int l = dfs(root->left, currMin, currMax);
        int r = dfs(root->right, currMin, currMax);
        
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};