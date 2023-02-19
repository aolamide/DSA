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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        bool rev = false;
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> s;
            for(int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                s.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            if(rev) {
                reverse(s.begin(), s.end());
            }
            rev = !rev;
            result.push_back(s);
        }
        
        return result;
    }
};