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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        helper(root, 0, targetSum, {});
        
        return result;
    }
    vector<vector<int>> result;
    void helper(TreeNode* root, int sumSoFar, int target, vector<int> targetPaths) {
        if(root) {
            sumSoFar += root->val;
            targetPaths.push_back(root->val);
            bool isLeaf = !root->left && !root->right;
            if(isLeaf && sumSoFar == target) {
                result.push_back(targetPaths);
                return;
            }

            helper(root->left, sumSoFar, target, targetPaths);
            helper(root->right, sumSoFar, target, targetPaths);
        }
    }
};