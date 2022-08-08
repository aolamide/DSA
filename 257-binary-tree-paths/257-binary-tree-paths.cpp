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
    void traverse(TreeNode* root, string acc, vector<string> &result) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            acc = acc + to_string(root->val);
            result.push_back(acc);
            return;
        }
        
        traverse(root->left, acc + to_string(root->val) + "->", result);
        traverse(root->right, acc + to_string(root->val) + "->", result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> result;
       string acc = "";
       traverse(root, acc, result);
       return result;
    }
};