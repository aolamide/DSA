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
    long total_sum = 0;
    long result = 0;
    void getTotalSum(TreeNode *root) {
        if(!root) return;
        total_sum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        
        long currSum = root->val + dfs(root->left) + dfs(root->right);
        
        result = max(result, ((total_sum - currSum) * currSum));

        return currSum;
        
    }
    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        dfs(root);
        
        return result % int(pow(10, 9) + 7);
    }
};