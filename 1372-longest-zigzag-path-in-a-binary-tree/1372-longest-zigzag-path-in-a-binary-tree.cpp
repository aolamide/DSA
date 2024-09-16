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
    int result = INT_MIN;
    void traverse(TreeNode* root, char dir, int count) {
        result = max(result, count);
        if(!root) {
            return;
        } 
        if(dir == 'l') {
            traverse(root->right, 'r', count + 1);
            traverse(root->left, 'l', 0);
        } else if(dir == 'r') {
            traverse(root->left, 'l', count + 1);
            traverse(root->right, 'r', 0);
        }
    }
    int longestZigZag(TreeNode* root) {  
        traverse(root->left, 'l', 0);
        traverse(root->right, 'r', 0);
        return result;
    }
};