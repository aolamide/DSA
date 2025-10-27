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
        if(!root) return {};

        vector<int> result;

        queue<TreeNode*> q;
        int currRowCount = 1;
        q.push(root);

        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);

            currRowCount--;
            if(currRowCount == 0) {
                result.push_back(currNode->val);
                currRowCount = q.size();
            }
        }

        return result;
    }
};

//bfs
//pick first node, add to results array, push children to queue

//start with count of 1 for root node
//after a node is treated, push children and decrement count
//if count is 0, that is a right side node
//count how many items are currently in queue and set count to that
//continue till end.