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
    vector<int> nodes;
    bool mirror(TreeNode *a, TreeNode *b) {
        if(!a && !b) return true;
        
        if(!a || !b) return false;

        return (a->val == b->val) && mirror(a->right, b->left) && mirror(a->left, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};