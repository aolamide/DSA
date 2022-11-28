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
    TreeNode* lca;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        bool isNode = root == p || root == q;
        
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p , q);
        
        if(isNode + left + right >=2) {
            lca = root;
        }
        
        return isNode || left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        
        return lca;
    }
};