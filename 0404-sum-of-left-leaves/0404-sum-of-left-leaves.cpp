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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int sum = 0;
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(curr.second && !curr.first->left && !curr.first->right) sum += curr.first->val;
            
            if(curr.first->left) q.push({curr.first->left, 1});
            if(curr.first->right) q.push({curr.first->right, 0});
        }
        
        return sum;
    }
};