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
    bool helper(TreeNode* root, int sumSoFar, int target) {
        if(!root) {
            return false;
        }
        sumSoFar += root->val;
        bool isLeaf = !root->left && !root->right;
        if(isLeaf && sumSoFar == target) return true;
        
        return helper(root->left, sumSoFar, target) || helper(root->right, sumSoFar, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        return helper(root, 0, targetSum);
    }
};