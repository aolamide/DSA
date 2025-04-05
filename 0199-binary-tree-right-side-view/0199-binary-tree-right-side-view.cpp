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
    vector<int> rightSideView(TreeNode* root) {
        //use bfs, keep count of how many nodes are in a level, and store last member of level.
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int levelCount = 1, currCount = 0;

        vector<int> result;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            if(++currCount == levelCount) {
                result.push_back(curr->val);
                levelCount = q.size();
                currCount = 0;
            }
        }
        return result;
    }
};