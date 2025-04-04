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
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if(!root) {
            return { 0, nullptr };
        }
        pair<int, TreeNode*> left = dfs(root->left);        
        pair<int, TreeNode*> right = dfs(root->right);
        //if depth of both are same, this node is current lowest ancestor
        if(left.first == right.first) {
            return { left.first + 1, root };
        }
        //else lowest ancestor is in left or right subtree
        else if(left.first > right.first) {
            return { left.first + 1, left.second };
        }
        else {
            return { right.first + 1, right.second };
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int, TreeNode*> result = dfs(root);
        return result.second;
    }
};