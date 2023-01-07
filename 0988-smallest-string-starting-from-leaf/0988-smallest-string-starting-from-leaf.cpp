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
    string s = "";
    string result = "";
    void bt(TreeNode* curr) {
        if(!curr) {
            return;
        }
        char c = 'a' + curr->val;
        s += c;
        
        if(!curr->left && !curr->right) {
            reverse(s.begin(), s.end());
            if(!result.size() || s < result) result = s;
            reverse(s.begin(), s.end());
        }
        bt(curr->left);
        bt(curr->right);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        bt(root);
        return result;
    }
};